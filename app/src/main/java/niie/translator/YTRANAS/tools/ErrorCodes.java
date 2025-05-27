package nie.translator.rtranslator.tools;

public class ErrorCodes {
    //errors

    //generals
    public static final int MISSED_CONNECTION = 5;
    public static final int ERROR=13;

    //locals
    public static final int MISSED_ARGUMENT = 0;
    public static final int MISSED_CREDENTIALS = 1;
    public static final int MAX_CREDIT_OFFET_REACHED = 11;

    //safetyNet
    public static final int SAFETY_NET_EXCEPTION = 8;
    public static final int MISSING_PLAY_SERVICES = 9;

    //tts
    public static final int GOOGLE_TTS_ERROR =100;
    public static final int MISSING_GOOGLE_TTS =101;

    //neural networks
    public static final int ERROR_LOADING_MODEL = 34;
    public static final int ERROR_EXECUTING_MODEL = 35;

    //language identification
    public static final int LANGUAGE_UNKNOWN = 15;
    public static final int FIRST_RESULT_FAIL = 16;
    public static final int SECOND_RESULT_FAIL = 17;
    public static final int BOTH_RESULTS_FAIL = 18;
    public static final int BOTH_RESULTS_SUCCESS = 19;
}
