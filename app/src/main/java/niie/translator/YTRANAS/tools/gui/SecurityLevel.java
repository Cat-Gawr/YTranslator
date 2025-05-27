package nie.translator.rtranslator.tools.gui;

import android.content.Context;
import android.text.Editable;
import android.util.AttributeSet;
import androidx.appcompat.widget.AppCompatTextView;
import nie.translator.rtranslator.R;


/**
 * Not used, this class is for the eventual use of accounts
 */
public class SecurityLevel extends AppCompatTextView {

    public SecurityLevel(Context context) {
        super(context);
    }

    public SecurityLevel(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public SecurityLevel(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    public void createTextWatcher(){

    }

    public void removeTextWatcher(){

    }

    public void updateSecurityLevel(Editable text) {
        if (text != null && text.length() > 0) {
            if (text.length() <= 4 && !getText().equals("sicurezza molto bassa")) {  //da sostituire con le risorse string
                setText("sicurezza molto bassa");
                setTextColor(GuiTools.getColor(getContext(), R.color.red));
            } else if (text.length() > 4 && text.length() <= 9 && !getText().equals("sicurezza bassa")) {
                setText("sicurezza bassa");
                setTextColor(GuiTools.getColor(getContext(), R.color.red));
            } else if (text.length() > 9 && text.length() <= 13 && !getText().equals("sicurezza media")) {
                setText("sicurezza media");
                setTextColor(GuiTools.getColor(getContext(), R.color.yellow));
            } else if (text.length() > 13 && text.length() <= 16 && !getText().equals("sicurezza alta")) {
                setText("sicurezza alta");
                setTextColor(GuiTools.getColor(getContext(), R.color.primary_dark));
            } else if (text.length() > 16 && !getText().equals("sicurezza molto alta")) {
                setText("sicurezza molto alta");
                setTextColor(GuiTools.getColor(getContext(), R.color.primary_dark));
            }
        }
    }
}


// quanta è sbagliata la vita. . . se non fumi non sei un figo..ti dicono il contrario,mas tu HAI UN CERVELLO
// VAI UOMO! NON SEI MICA UN COGLIONE ! 
