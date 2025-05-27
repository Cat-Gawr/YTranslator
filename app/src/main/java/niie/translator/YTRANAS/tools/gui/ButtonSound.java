package nie.translator.rtranslator.tools.gui;

import android.content.Context;
import android.util.AttributeSet;
import nie.translator.rtranslator.R;


public class ButtonSound extends DeactivableButton {
    private boolean isMute=false;

    public ButtonSound(Context context) {
        super(context);
    }

    public ButtonSound(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public ButtonSound(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    @Override
    public void deactivate(int reason) {
        super.deactivate(reason);
        if(reason == DEACTIVATED_FOR_TTS_ERROR) {
            setMute(true);
        }
    }

    public boolean isMute() {
        return isMute;
    }

    public void setMute(boolean mute) {
        if(isMute!=mute){
            if(mute){
                setImageDrawable(getResources().getDrawable(R.drawable.sound_mute_icon,null));
            }else{
                setImageDrawable(getResources().getDrawable(R.drawable.sound_icon,null));
            }
        }
        isMute = mute;
    }
}
