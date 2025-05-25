package nie.translator.rtranslator.settings;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.util.AttributeSet;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;

import androidx.appcompat.app.AlertDialog;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.preference.Preference;
import androidx.preference.PreferenceViewHolder;

import com.google.android.material.textfield.TextInputLayout;

import java.util.ArrayList;

import nie.translator.rtranslator.Global;
import nie.translator.rtranslator.R;
import nie.translator.rtranslator.tools.gui.GuiTools;
import nie.translator.rtranslator.bluetooth.tools.BluetoothTools;


public class UserNamePreference extends Preference {
    private TextView username;
    private Activity activity;
    private Global global;
    private Context context;

    public UserNamePreference(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        this.context = context;
    }

    public UserNamePreference(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        this.context = context;
    }

    public UserNamePreference(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.context = context;
    }

    public UserNamePreference(Context context) {
        super(context);
        this.context = context;
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);
        username = (TextView) holder.findViewById(R.id.username);
        ImageButton editUsernameButton = (ImageButton) holder.findViewById(R.id.editNameButton);
        ConstraintLayout container = (ConstraintLayout) holder.findViewById(R.id.constraintLayout);

        //user name initialization
        username.setText(global.getName());
        View.OnClickListener clickListener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (activity != null) {
                    final GuiTools.EditTextDialog editTextDialog = GuiTools.createEditTextDialog(activity, username.getText().toString(), global.getResources().getString(R.string.dialog_insert_name), R.layout.dialog_edit_name);
                    final AlertDialog dialog = editTextDialog.getDialog();
                    final EditText editText = editTextDialog.getEditText();
                    final TextInputLayout editTextLayout = editTextDialog.getEditTextLayout();
                    dialog.setOnShowListener(new DialogInterface.OnShowListener() {
                        @Override
                        public void onShow(DialogInterface dialogInterface) {
                            dialog.getButton(AlertDialog.BUTTON_POSITIVE).setOnClickListener(new View.OnClickListener() {
                                @Override
                                public void onClick(View view) {
                                    String savedName = editText.getText().toString();
                                    if (savedName.length() > 0) {
                                        //compatibility check with supported characters
                                        ArrayList<Character> supportedCharacters = BluetoothTools.getSupportedUTFCharacters(context);
                                        boolean equals = true;
                                        for (int i = 0; i < savedName.length() && equals; i++) {
                                            if (!supportedCharacters.contains(Character.valueOf(savedName.charAt(i)))) {
                                                equals = false;
                                            }
                                        }

                                        if (equals) {
                                            global.setName(savedName);
                                            username.setText(savedName);
                                            dialog.dismiss();
                                        } else {
                                            editTextLayout.setError(global.getResources().getString(R.string.error_wrong_username) + BluetoothTools.getSupportedNameCharactersString(global));
                                        }
                                    } else {
                                        editTextLayout.setError(global.getResources().getString(R.string.error_missing_username));
                                    }
                                }
                            });
                        }
                    });
                    dialog.show();
                }
            }
        };
        container.setOnClickListener(clickListener);
        editUsernameButton.setOnClickListener(clickListener);
    }

    public void setActivity(Activity activity) {
        this.activity = activity;
        this.global = (Global) activity.getApplication();
    }
}
