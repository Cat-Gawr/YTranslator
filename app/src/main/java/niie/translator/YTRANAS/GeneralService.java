package nie.translator.rtranslator;

import android.app.Service;
import android.content.Intent;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Messenger;
import android.os.RemoteException;
import androidx.annotation.Nullable;


public abstract class GeneralService extends Service {
    //commands
    public static final int INITIALIZE_COMMUNICATION = 50;
    //callbacks
    public static final int ON_ERROR = 50;
    //objects
    private Messenger clientMessenger;


    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    protected boolean executeCommand(int command, Bundle data) {
        switch (command) {
            case INITIALIZE_COMMUNICATION: {
                clientMessenger = data.getParcelable("messenger");
                return true;
            }
        }
        return false;
    }

    /*@Override
    public boolean onUnbind(Intent intent) {
        //si cancella l' handler e di conseguenza si interrompe l'invio al fragment
        clientMessenger = null;
        return super.onUnbind(intent);
    }*/

    protected void notifyToClient(Bundle bundle) {
        if (clientMessenger != null) {
            android.os.Message message = android.os.Message.obtain();
            message.setData(bundle);
            try {
                clientMessenger.send(message);
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }

    public void notifyError(int[] reasons, long value) {
        Bundle bundle = new Bundle();
        bundle.putInt("callback", ON_ERROR);
        bundle.putIntArray("reasons",reasons);
        bundle.putLong("value",value);
        notifyToClient(bundle);
    }
}
