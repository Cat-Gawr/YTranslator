
package nie.translator.rtranslator.voice_translation.neural_networks;


public class NeuralNetworkApiResult extends NeuralNetworkApiText {
    private double confidenceScore=0;
    private boolean isFinal;

    public NeuralNetworkApiResult(String text, double confidenceScore, boolean isFinal){
        super(text);
        this.confidenceScore=confidenceScore;
        this.isFinal=isFinal;
    }

    public NeuralNetworkApiResult(String text, boolean isFinal){
        super(text);
        this.isFinal=isFinal;
    }

    public NeuralNetworkApiResult(String text){
        super(text);
    }

    public double getConfidenceScore() {
        return confidenceScore;
    }

    public void setConfidenceScore(float confidenceScore) {
        this.confidenceScore = confidenceScore;
    }

    public boolean isFinal() {
        return isFinal;
    }

    public void setFinal(boolean aFinal) {
        isFinal = aFinal;
    }
}
