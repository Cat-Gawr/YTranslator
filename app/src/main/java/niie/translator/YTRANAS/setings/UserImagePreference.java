
package nie.translator.rtranslator.settings;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.ImageView;
import androidx.preference.Preference;
import androidx.preference.PreferenceViewHolder;
import nie.translator.rtranslator.R;


public class UserImagePreference extends Preference {
    private ImageView image;
    private LifecycleListener lifecycleListener;

    public UserImagePreference(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
    }

    public UserImagePreference(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    public UserImagePreference(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public UserImagePreference(Context context) {
        super(context);
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);
        image= (ImageView) holder.findViewById(R.id.user_image_settings);
        if(lifecycleListener!=null){
            lifecycleListener.onBindViewHolder();
        }
    }

    public ImageView getImage(){
        return image;
    }

    public void setLifecycleListener(LifecycleListener lifecycleListener) {
        this.lifecycleListener=lifecycleListener;
    }

    public interface LifecycleListener{
        void onBindViewHolder();
    }
}
