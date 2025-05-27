
package nie.translator.rtranslator.tools.gui;

import android.content.Context;
import android.os.Handler;
import android.util.AttributeSet;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import nie.translator.rtranslator.tools.gui.animations.CustomAnimator;

public class WalkieTalkieButton extends FloatingActionButton {
    public static final int STATE_SINGLE=0;
    public static final int STATE_CONNECTING=2;
    private int state;
    private Handler eventHandler= new Handler();
    private CustomAnimator animator= new CustomAnimator();

    public WalkieTalkieButton(Context context) {
        super(context);
        setDrawingCacheEnabled(true);
    }

    public WalkieTalkieButton(Context context, AttributeSet attrs) {
        super(context, attrs);
        setDrawingCacheEnabled(true);
    }

    public WalkieTalkieButton(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        setDrawingCacheEnabled(true);
    }

    public int getState() {
        return state;
    }

    public void setState(int state) {
        /*int oldState=this.state;
        AnimatedVectorDrawable oldIcon=null;
        AnimatedVectorDrawable newIcon=null;

        if(oldState!=state) {
            switch (oldState) {
                case STATE_SINGLE:
                    oldIcon = (AnimatedVectorDrawable) getResources().getDrawable(R.drawable.dwindable_mic_icon, null);
                    break;
                case STATE_MULTIPLE:
                    oldIcon = (AnimatedVectorDrawable) getResources().getDrawable(R.drawable.dwindable_mic_none, null);
                    break;
                case STATE_CONNECTING:
                    oldIcon=null;
                    break;
            }

            switch (state) {
                case STATE_SINGLE:
                    newIcon = (AnimatedVectorDrawable) getResources().getDrawable(R.drawable.enlargable_mic_icon, null);
                    break;
                case STATE_MULTIPLE:
                    newIcon = (AnimatedVectorDrawable) getResources().getDrawable(R.drawable.enlargable_mic_none, null);
                    break;
                case STATE_CONNECTING:
                    newIcon=null;
                    break;
            }

            if(oldIcon==null){
                //cambio icona senza animazione
                setOnClickListener(clickListener);
                setImageDrawable(newIcon);

            }else if(newIcon==null){
                //cambio icona senza animazione
                setOnClickListener(connectingClickListener);
                setImageDrawable(null);

            }else{
                //cambio icona con animazione
                animator.animateIconChange(this,newIcon);
            }
        }

        this.state=state;*/
        this.state=state;

    }
}
