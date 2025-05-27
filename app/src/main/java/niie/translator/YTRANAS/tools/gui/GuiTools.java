package nie.translator.rtranslator.tools.gui;

import android.app.Activity;
import android.content.Context;
import android.content.res.ColorStateList;
import android.view.View;
import android.view.WindowManager;
import android.widget.EditText;
import androidx.appcompat.app.AlertDialog;
import com.google.android.material.textfield.TextInputLayout;
import java.util.Objects;
import nie.translator.rtranslator.R;

public class GuiTools {
    public static EditTextDialog createEditTextDialog(Activity activity, String text, String title, int layout) {
        final View editDialogLayout = activity.getLayoutInflater().inflate(layout, null);
        final EditText editText = editDialogLayout.findViewById(R.id.editText);
        final TextInputLayout editTextLayout = editDialogLayout.findViewById(R.id.editTextLayout);
        if (text != null) {
            editText.setText(text);
            editText.setSelection(text.length());
        }

        final AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setPositiveButton(android.R.string.ok, null);
        builder.setNegativeButton(android.R.string.cancel, null);

        final AlertDialog dialog = builder.create();
        dialog.setView(editDialogLayout);
        Objects.requireNonNull(dialog.getWindow()).setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_VISIBLE);
        return new EditTextDialog(dialog, editText, editTextLayout);
    }

    public static class EditTextDialog {
        private AlertDialog dialog;
        private EditText editText;
        private TextInputLayout editTextLayout;

        public EditTextDialog(AlertDialog dialog, EditText editText, TextInputLayout editTextLayout) {
            this.dialog = dialog;
            this.editText = editText;
            this.editTextLayout = editTextLayout;
        }

        public AlertDialog getDialog() {
            return dialog;
        }

        public EditText getEditText() {
            return editText;
        }

        public TextInputLayout getEditTextLayout() {
            return editTextLayout;
        }
    }

    public static AlertDialog createDialog(Activity activity, String title, String text) {
        final AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setTitle(title);
        builder.setMessage(text);
        builder.setPositiveButton(android.R.string.ok, null);

        return builder.create();
    }

    public static int getColor(Context context, int colorCode) {
        return context.getResources().getColor(colorCode, null);
    }

    public static ColorStateList getColorStateList(Context context, int colorCode) {
        return context.getResources().getColorStateList(colorCode, null);
    }
}
