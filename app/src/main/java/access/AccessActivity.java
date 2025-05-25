
package nie.translator.rtranslator.access;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;
import nie.translator.rtranslator.GeneralActivity;
import nie.translator.rtranslator.Global;
import nie.translator.rtranslator.R;


public class AccessActivity extends GeneralActivity {
    public static final int USER_DATA_FRAGMENT = 0;
    public static final int NOTICE_FRAGMENT = 1;
    public static final int DOWNLOAD_FRAGMENT = 2;
    private Fragment fragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_access);

        View decorView = getWindow().getDecorView();
        decorView.setSystemUiVisibility(View.SYSTEM_UI_FLAG_LAYOUT_STABLE | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN | View.SYSTEM_UI_FLAG_LIGHT_STATUS_BAR);

        if (savedInstanceState != null) {
            //Restore the fragment's instance
            fragment = getSupportFragmentManager().getFragment(savedInstanceState, "fragment_inizialization");
        } else {
            final SharedPreferences sharedPreferences = this.getSharedPreferences("default", Context.MODE_PRIVATE);
            String savedUserName = sharedPreferences.getString("name", "");
            if(savedUserName.length()>0){  //means that the user has already inserted the info in UserDataFragment, so we can start directly the DownloadFragment
                startFragment(DOWNLOAD_FRAGMENT, null);
            }else{
                startFragment(NOTICE_FRAGMENT, null);
            }
        }
    }

    @Override
    protected void onStart() {
        Global global = (Global) getApplication();
        if(global != null){
            global.setAccessActivity(this);
        }
        super.onStart();  //called here because otherwise the onStart of the DownloadFragment is called before this onStart, and this could cause problems.
    }

    @Override
    protected void onStop() {
        super.onStop();
        Global global = (Global) getApplication();
        if(global != null){
            global.setAccessActivity(null);
        }
    }

    public void startFragment(int action, Bundle bundle) {
        switch (action) {
            case USER_DATA_FRAGMENT: {
                UserDataFragment userDataFragment = new UserDataFragment();
                if (bundle != null) {
                    userDataFragment.setArguments(bundle);
                }
                FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
                transaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
                transaction.replace(R.id.fragment_initialization_container, userDataFragment);
                transaction.commit();
                fragment = userDataFragment;
                break;
            }
            case NOTICE_FRAGMENT: {
                NoticeFragment noticeFragment = new NoticeFragment();
                if (bundle != null) {
                    noticeFragment.setArguments(bundle);
                }
                FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
                transaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
                transaction.replace(R.id.fragment_initialization_container, noticeFragment);
                transaction.commit();
                fragment = noticeFragment;
                break;
            }
            case DOWNLOAD_FRAGMENT: {
                DownloadFragment downloadFragment = new DownloadFragment();
                if (bundle != null) {
                    downloadFragment.setArguments(bundle);
                }
                FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
                transaction.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
                transaction.replace(R.id.fragment_initialization_container, downloadFragment);
                transaction.commit();
                fragment = downloadFragment;
                break;
            }
        }
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        //Save the fragment's instance
        getSupportFragmentManager().putFragment(outState, "fragment_inizialization", fragment);
    }


    @Override
    public void onBackPressed() {
        if(fragment instanceof UserDataFragment){
            startFragment(NOTICE_FRAGMENT,null);
            return;
        }
        if(fragment instanceof DownloadFragment){
            startFragment(USER_DATA_FRAGMENT,null);
            return;
        }
        super.onBackPressed();
    }
}
