package nie.translator.rtranslator.tools.services_communication;

public abstract class ServiceCommunicatorListener {
    public abstract void onServiceCommunicator(ServiceCommunicator serviceCommunicator);
    public void onFailure(int[]reasons, long value){}
}
