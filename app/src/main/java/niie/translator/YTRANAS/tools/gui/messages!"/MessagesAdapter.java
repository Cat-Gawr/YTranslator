
package nie.translator.rtranslator.tools.gui.messages;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

import nie.translator.rtranslator.R;

/** Is used to connect to the RecycleView, which functions as a ListView, a list of strings, which will be inserted in the ViewHolder layout and this will be inserted in the list**/
public class MessagesAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {
    private static final int MINE = 0;
    private static final int NON_MINE = 1;
    //private static final int PREVIEW = 2;
    private ArrayList<GuiMessage> mResults = new ArrayList<>();
    private Callback callback;

    public MessagesAdapter(ArrayList<GuiMessage> messages, @NonNull Callback callback) {
        this.callback = callback;
        if (messages != null) {
            if (messages.size() > 0) {
                callback.onFirstItemAdded();
            }
            mResults.addAll(messages);
            notifyItemRangeInserted(0, messages.size() - 1);
        }
    }

    @NonNull
    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        switch (viewType) {
            case MINE:
                return new SendHolder(LayoutInflater.from(parent.getContext()), parent);
            case NON_MINE:
                return new ReceivedHolder(LayoutInflater.from(parent.getContext()), parent);
        }
        return new SendHolder(LayoutInflater.from(parent.getContext()), parent);  // to not return null
    }

    @Override
    public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
        if (holder instanceof MessageHolder) {
            GuiMessage message = mResults.get(position);
            if (holder instanceof ReceivedHolder && message.getMessage().getSender() != null) {
                ((ReceivedHolder) holder).text.setVisibility(View.GONE);
                ((ReceivedHolder) holder).containerSender.setVisibility(View.VISIBLE);
                ((ReceivedHolder) holder).sender.setText(message.getMessage().getSender().getName());
                Log.d("recyclerview", "RecyclerView bind sender");
            }
            ((MessageHolder) holder).setText(message.getMessage().getText());
            Log.d("recyclerview", "RecyclerView bind text");
            //holder.itemView.requestLayout();
        }
    }

    @Override
    public int getItemViewType(int position) {
        GuiMessage message = mResults.get(position);
        if (message.isMine()) {
            return MINE;
        } else {
            return NON_MINE;
        }
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public int getItemCount() {
        return mResults.size();
    }

    @Override
    public void onViewRecycled(@NonNull RecyclerView.ViewHolder holder) {
        super.onViewRecycled(holder);
    }

    @Override
    public boolean onFailedToRecycleView(@NonNull RecyclerView.ViewHolder holder) {
        return super.onFailedToRecycleView(holder);
    }

    public void addMessage(GuiMessage message) {
        if (getItemCount() == 0) {
            callback.onFirstItemAdded();
        }
        mResults.add(message);
        notifyItemInserted(getItemCount() - 1);
    }

    public void setMessage(int index, GuiMessage message) {
        mResults.set(index, message);
        //notifyItemRangeChanged(0, getItemCount());
        notifyItemChanged(index);
    }

    public int getMessageIndex(long messageID){
        for(int i = 0; i < mResults.size(); i++){
            if(mResults.get(i).getMessageID() == messageID){
                return i;
            }
        }
        return -1;
    }

    @Nullable
    public GuiMessage getMessage(long messageID){
        for(int i = 0; i < mResults.size(); i++){
            if(mResults.get(i).getMessageID() == messageID){
                return mResults.get(i);
            }
        }
        return null;
    }

    public GuiMessage getMessage(int index) {
        return mResults.get(index);
    }

    public int indexOf(GuiMessage message) {
        return mResults.indexOf(message);
    }

    public ArrayList<GuiMessage> getMessages() {
        return mResults;
    }

    /** The layout for each item in the RecicleView list*/
    private static class ReceivedHolder extends RecyclerView.ViewHolder implements MessageHolder {
        TextView text;
        LinearLayout containerSender;
        TextView textSender;
        TextView sender;

        ReceivedHolder(LayoutInflater inflater, ViewGroup parent) {
            super(inflater.inflate(R.layout.component_message_received, parent, false));
            text = itemView.findViewById(R.id.text_content);

            containerSender = itemView.findViewById(R.id.sender_container);
            textSender = itemView.findViewById(R.id.text_content2);
            sender = itemView.findViewById(R.id.text_sender);
        }

        @Override
        public void setText(String text) {
            this.textSender.setText(text);
            this.text.setText(text);
        }
    }

    /** The layout for each item in the RecicleView list*/
    private static class SendHolder extends RecyclerView.ViewHolder implements MessageHolder {
        TextView text;
        CardView card;

        SendHolder(LayoutInflater inflater, ViewGroup parent) {
            super(inflater.inflate(R.layout.component_message_send, parent, false));
            text = itemView.findViewById(R.id.text);
            card = itemView.findViewById(R.id.card);
        }

        @Override
        public void setText(String text) {
            this.text.setText(text);
        }
    }

    interface MessageHolder {
        void setText(String text);
    }

    public interface Callback {
        void onFirstItemAdded();
    }
}
