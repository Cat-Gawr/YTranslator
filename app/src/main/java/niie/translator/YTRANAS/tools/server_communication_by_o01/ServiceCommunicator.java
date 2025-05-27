
package nie.translator.rtranslator.tools.services_communication;

import android.os.Bundle;
import android.os.Handler;
import android.os.Messenger;
import android.os.RemoteException;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public abstract class ServiceCommunicator {
    protected Handler serviceHandler;
    protected Messenger serviceMessenger;
    private int id;

    protected ServiceCommunicator(@NonNull int id1) {
        this.id = id1;
    }

    public void initializeCommunication(Messenger serviceMessenger) {
        this.serviceMessenger = serviceMessenger;
    }

    public void stopCommunication() {
        this.serviceMessenger = null;
    }

    protected void sendToService(Bundle bundle) {
        if (serviceMessenger != null) {
            android.os.Message message = android.os.Message.obtain();
            message.setData(bundle);
            try {
                serviceMessenger.send(message);
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }

    public Messenger getServiceMessenger() {
        return serviceMessenger;
    }

    public boolean isCommunicating() {
        return serviceMessenger != null;
    }

    public abstract void addCallback(ServiceCallback serviceCallback);

    public abstract int removeCallback(ServiceCallback serviceCallback);

    public int getId() {
        return id;
    }

    @Override
    public boolean equals(@Nullable Object obj) {
        if(obj instanceof ServiceCommunicator){
            ServiceCommunicator serviceCommunicator= (ServiceCommunicator) obj;
            return serviceCommunicator.getId() == id;
        }else{
            return false;
        }
    }
}
