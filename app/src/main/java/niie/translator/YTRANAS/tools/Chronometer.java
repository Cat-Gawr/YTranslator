package nie.translator.rtranslator.tools;

public class Chronometer {
    public static final int SECONDS=0;
    public static final int MILLI_SECONDS=1;

    private long startTime;

    public void start(){
        startTime=System.currentTimeMillis();
    }

    public float stop(int outputType){
        int divider=0;
        switch (outputType){
            case SECONDS:{
                divider=1000;
                break;
            }
            case MILLI_SECONDS:{
                divider=1;
                break;
            }
        }
        return (System.currentTimeMillis()-startTime)/divider;
    }
}
