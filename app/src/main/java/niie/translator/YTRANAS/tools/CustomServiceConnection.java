package nie.translator.rtranslator.tools;

import android.content.ComponentName;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.Messenger;
import java.util.ArrayList;
import nie.translator.rtranslator.tools.services_communication.ServiceCallback;
import nie.translator.rtranslator.tools.services_communication.ServiceCommunicator;
import nie.translator.rtranslator.tools.services_communication.ServiceCommunicatorListener;

public class CustomServiceConnection implements ServiceConnection {
    private ServiceCommunicator serviceCommunicator;
    private ArrayList<ServiceCallback> callbacksToAddOnBind = new ArrayList<>();
    private ArrayList<ServiceCommunicatorListener> callbacksToRespondOnBind = new ArrayList<>();

    public CustomServiceConnection(ServiceCommunicator serviceCommunicator){
        this.serviceCommunicator=serviceCommunicator;
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder iBinder) {
        serviceCommunicator.initializeCommunication(new Messenger(iBinder));
        for(int i = 0; i< callbacksToAddOnBind.size(); i++) {
            serviceCommunicator.addCallback(callbacksToAddOnBind.get(i));
        }
        for(int i = 0; i< callbacksToRespondOnBind.size(); i++) {
            ServiceCommunicatorListener responseListener1= callbacksToRespondOnBind.get(i);
            if(responseListener1!=null) {
                responseListener1.onServiceCommunicator(serviceCommunicator);
            }
        }
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {}

    public void onServiceDisconnected(){
        for(int i=0;i<callbacksToAddOnBind.size();i++) {
            serviceCommunicator.removeCallback(callbacksToAddOnBind.get(i));
        }
        serviceCommunicator.stopCommunication();
    }

    public ServiceCommunicator getServiceCommunicator() {
        return serviceCommunicator;
    }

    public void addCallbacks(ServiceCallback serviceCallback, ServiceCommunicatorListener responseListener){
        callbacksToAddOnBind.add(serviceCallback);
        callbacksToRespondOnBind.add(responseListener);
    }
}
