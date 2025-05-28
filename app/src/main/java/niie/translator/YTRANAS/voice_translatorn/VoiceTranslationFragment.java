
package nie.translator.rtranslator.voice_translation;

import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.WindowManager;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import androidx.annotation.CallSuper;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.LinearSmoothScroller;
import androidx.recyclerview.widget.RecyclerView;
import java.util.ArrayList;
import nie.translator.rtranslator.Global;
import nie.translator.rtranslator.R;
import nie.translator.rtranslator.tools.ErrorCodes;
import nie.translator.rtranslator.tools.gui.ButtonKeyboard;
import nie.translator.rtranslator.tools.gui.ButtonMic;
import nie.translator.rtranslator.tools.gui.ButtonSound;
import nie.translator.rtranslator.tools.gui.DeactivableButton;
import nie.translator.rtranslator.tools.gui.MicrophoneComunicable;
import nie.translator.rtranslator.tools.gui.messages.GuiMessage;
import nie.translator.rtranslator.tools.gui.messages.MessagesAdapter;

public abstract class VoiceTranslationFragment extends Fragment implements MicrophoneComunicable {
    //gui
    public static final int TIME_FOR_SCROLLING = 50;
    protected VoiceTranslationActivity activity;
    protected Global global;
    protected MessagesAdapter mAdapter;
    protected RecyclerView mRecyclerView;
    protected TextView description;
    protected View.OnClickListener micClickListener;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mRecyclerView = view.findViewById(R.id.recycler_view);
        description = view.findViewById(R.id.description);
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        activity = (VoiceTranslationActivity) requireActivity();
        global = (Global) activity.getApplication();
        LinearLayoutManager layoutManager = new LinearLayoutManager(activity);
        layoutManager.setStackFromEnd(true);
        mRecyclerView.setLayoutManager(layoutManager);
        mRecyclerView.setItemAnimator(new DefaultItemAnimator(){
            @Override
            public boolean animateChange(RecyclerView.ViewHolder oldHolder, RecyclerView.ViewHolder newHolder, int fromX, int fromY, int toX, int toY) {
                dispatchChangeFinished(oldHolder, true);
                dispatchChangeFinished(newHolder, false);
                return true;
            }
        });
        //mRecyclerView.setItemAnimator(null);
        mRecyclerView.setHasFixedSize(true);
    }

    protected abstract void connectToService();

    protected abstract void deactivateInputs(int cause);

    protected abstract void activateInputs(boolean start);

    public abstract void restoreAttributesFromService();

    @Override
    public void onStart() {
        super.onStart();
        //we set the option to compress ui when the keyboard is shown
        activity.getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_ADJUST_RESIZE);
    }

    @Override
    public void onStop() {
        super.onStop();
        deactivateInputs(DeactivableButton.DEACTIVATED);
        //isChangingConfigurations is true when the screen rotates or in general we recreate the activity for some other changes
        if (activity.getCurrentFragment() != VoiceTranslationActivity.DEFAULT_FRAGMENT && activity.getCurrentFragment() != VoiceTranslationActivity.PAIRING_FRAGMENT && !activity.isChangingConfigurations()) {
            Toast.makeText(activity, getResources().getString(R.string.toast_working_background), Toast.LENGTH_SHORT).show();
        }
    }

    protected void onFailureConnectingWithService(int[] reasons, long value) {
        for (int aReason : reasons) {
            switch (aReason) {
                case ErrorCodes.MISSED_ARGUMENT:
                case ErrorCodes.SAFETY_NET_EXCEPTION:
                case ErrorCodes.MISSED_CONNECTION:
                    //creation of the dialog.
                    AlertDialog.Builder builder = new AlertDialog.Builder(activity);
                    builder.setMessage(R.string.error_internet_lack_accessing);
                    builder.setNegativeButton(R.string.exit, new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            activity.exitFromVoiceTranslation();
                        }
                    });
                    builder.setPositiveButton(R.string.retry, new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            connectToService();
                        }
                    });
                    AlertDialog dialog = builder.create();
                    dialog.setCanceledOnTouchOutside(false);
                    dialog.show();
                    break;
                case ErrorCodes.MISSING_GOOGLE_TTS:
                    activity.showMissingGoogleTTSDialog(null);
                    break;
                case ErrorCodes.GOOGLE_TTS_ERROR:
                    activity.showGoogleTTSErrorDialog(new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            connectToService();
                        }
                    });
                    break;
                default:
                    activity.onError(aReason, value);
                    break;
            }
        }
    }
}
