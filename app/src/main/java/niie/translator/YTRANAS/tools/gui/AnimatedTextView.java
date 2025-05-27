
package nie.translator.rtranslator.tools.gui;

import android.animation.Animator;
import android.animation.AnimatorSet;
import android.content.Context;
import android.util.AttributeSet;
import android.view.ViewGroup;
import androidx.appcompat.widget.AppCompatTextView;
import nie.translator.rtranslator.R;
import nie.translator.rtranslator.tools.gui.animations.CustomAnimator;

public class AnimatedTextView extends AppCompatTextView {
    CustomAnimator animator = new CustomAnimator();
    private float xmlWidth = ViewGroup.LayoutParams.WRAP_CONTENT;  //we use this to retrieve the correct width for the end of the animation

    public AnimatedTextView(Context context) {
        super(context);
        setSingleLine(true);
    }

    public AnimatedTextView(Context context, AttributeSet attrs) {
        super(context, attrs);
        setSingleLine(true);
        final String xmlns = "http://schemas.android.com/apk/res/android";
        try {
            float value = attrs.getAttributeIntValue(xmlns, "layout_width", -10);
            if(value == ViewGroup.LayoutParams.MATCH_PARENT){
                measure(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
                xmlWidth = getMeasuredWidth();
            }else if(value != ViewGroup.LayoutParams.WRAP_CONTENT){
                xmlWidth = -3;
            }
        }catch (Exception ignored){}
    }

    public AnimatedTextView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        setSingleLine(true);
        final String xmlns = "http://schemas.android.com/apk/res/android";
        try {
            float value = attrs.getAttributeIntValue(xmlns, "layout_width", -10);
            if(value == ViewGroup.LayoutParams.MATCH_PARENT){
                measure(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
                xmlWidth = getMeasuredWidth();
            }else if(value != ViewGroup.LayoutParams.WRAP_CONTENT){
                xmlWidth = -3;
            }
        }catch (Exception ignored){}
    }

    public void setText(final String text, boolean animated){
        if(animated){
            AnimatorSet animatorSet= new AnimatorSet();

            final int duration = getResources().getInteger(R.integer.durationStandard);
            String oldText = getText().toString();
            setText(text);
            final int newWidth;
            if(xmlWidth == -3) {
                newWidth = getWidth();
            } else if(xmlWidth > 0){
                newWidth = (int) xmlWidth;
            } else {
                measure(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
                newWidth = getMeasuredWidth();
            }
            setText(oldText);

            Animator disappearAnimator = animator.createAnimatorAlpha(this,1f,0f, duration);
            disappearAnimator.addListener(new Animator.AnimatorListener() {
                @Override
                public void onAnimationStart(Animator animation) {}
                @Override
                public void onAnimationEnd(Animator animation) {
                    AnimatedTextView.super.setText(text);
                    animator.createAnimatorAlpha(AnimatedTextView.this,0f,1f, duration).start();
                }
                @Override
                public void onAnimationCancel(Animator animation) {}
                @Override
                public void onAnimationRepeat(Animator animation) {}
            });
            Animator enlargeAnimator = animator.createAnimatorWidth(this,getWidth(),newWidth,duration*2);

            animatorSet.play(disappearAnimator).with(enlargeAnimator);
            animatorSet.start();
        }else {
            setText(text);
        }
    }
}
