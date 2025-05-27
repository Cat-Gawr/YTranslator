
package nie.translator.rtranslator.tools.gui;

import androidx.annotation.Nullable;
import nie.translator.rtranslator.tools.gui.peers.Listable;

public class WeightElement implements Comparable {
    private Listable element;
    private int weight=0;

    public WeightElement(Listable element, int weight) {
        this.element = element;
        this.weight = weight;
    }

    public WeightElement(Listable element) {
        this.element = element;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public Listable getElement() {
        return element;
    }

    public void setElement(Listable element) {
        this.element = element;
    }


    @Override
    public int compareTo(Object o) {
        if (o instanceof WeightElement) {
            WeightElement weightElement = (WeightElement) o;
            return weight - weightElement.getWeight();
        }
        return 0;
    }

    @Override
    public boolean equals(@Nullable Object obj) {
        if(obj instanceof WeightElement){
            WeightElement weightElement= (WeightElement) obj;
            return element.equals(weightElement.getElement());
        }
        return false;
    }
}
