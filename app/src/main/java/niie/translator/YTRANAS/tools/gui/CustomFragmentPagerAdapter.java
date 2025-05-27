
package nie.translator.rtranslator.tools.gui;

import android.content.Context;
import android.view.ViewGroup;
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;

import java.util.List;

public class CustomFragmentPagerAdapter extends FragmentPagerAdapter {
    private Context context;
    private List<String> titles;
    private Fragment[] fragments;

    public CustomFragmentPagerAdapter(Context context, FragmentManager fragmentManager, List<String> titles, Fragment[] fragments) {
        super(fragmentManager);
        this.context = context;
        this.titles = titles;
        this.fragments = fragments;
    }

    @Override
    public Fragment getItem(int position) {
        //return MyFragment.newInstance();
        return fragments[position];
    }

    @NonNull
    @Override
    public Object instantiateItem(@NonNull ViewGroup container, int position) {
        return super.instantiateItem(container, position);
    }

    @Override
    public CharSequence getPageTitle(int position) {
        //return CONTENT[position % CONTENT.length].toUpperCase();
        return titles.get(position);
    }

    @Override
    public int getCount() {
        // return CONTENT.length;
        return fragments.length;
    }

    public Fragment getFragment(int position) {
        return fragments[position];
    }

    @Override
    public int getItemPosition(@NonNull Object object) {
        return POSITION_NONE;
    }
}
