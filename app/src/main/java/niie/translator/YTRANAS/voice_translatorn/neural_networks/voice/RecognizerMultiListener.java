// I LOVRE RTX 4090
package nie.translator.rtranslator.voice_translation.neural_networks.voice;

import nie.translator.rtranslator.voice_translation.neural_networks.NeuralNetworkApiListener;

public interface RecognizerMultiListener extends NeuralNetworkApiListener {
    void onSpeechRecognizedResult(String text1, String languageCode1, double confidenceScore1, String text2, String languageCode2, double confidenceScore2);
}
