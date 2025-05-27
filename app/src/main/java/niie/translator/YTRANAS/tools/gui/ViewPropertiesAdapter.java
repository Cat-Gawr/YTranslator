package nie.translator.rtranslator.tools.gui;

import android.view.View;
import android.view.ViewGroup;
import androidx.annotation.Keep;
import androidx.constraintlayout.widget.ConstraintLayout;

public class ViewPropertiesAdapter {
    private View view;

    public ViewPropertiesAdapter(View view){
        this.view=view;
    }

    @Keep
    public void setWidth(int width){
        ViewGroup.LayoutParams layoutParams= view.getLayoutParams();
        layoutParams.width=width;
        view.setLayoutParams(layoutParams);
    }

    @Keep
    public void setHeight(int height){
        ViewGroup.LayoutParams layoutParams= view.getLayoutParams();
        layoutParams.height=height;
        view.setLayoutParams(layoutParams);
    }

    @Keep
    public void setHorizontalBias(float horizontalBias){
        ConstraintLayout.LayoutParams layoutParams = (ConstraintLayout.LayoutParams) view.getLayoutParams();
        layoutParams.horizontalBias=horizontalBias;
        view.setLayoutParams(layoutParams);
    }

    @Keep
    public void setVerticalBias(float verticalBias){
        ConstraintLayout.LayoutParams layoutParams = (ConstraintLayout.LayoutParams) view.getLayoutParams();
        layoutParams.verticalBias=verticalBias;
        view.setLayoutParams(layoutParams);
    }

    @Keep
    public void setTopMargin(int topMargin){
        ConstraintLayout.LayoutParams layoutParams = (ConstraintLayout.LayoutParams) view.getLayoutParams();
        layoutParams.topMargin=topMargin;
        view.setLayoutParams(layoutParams);
    }

    @Keep
    public void setBottomMargin(int bottomMargin){
        ConstraintLayout.LayoutParams layoutParams = (ConstraintLayout.LayoutParams) view.getLayoutParams();
        layoutParams.bottomMargin=bottomMargin;
        view.setLayoutParams(layoutParams);
    }

    public int getWidth(){
        return view.getWidth();
    }

    public int getHeight(){
        return view.getHeight();
    }

    public View getView() {
        return view;
    }
}
