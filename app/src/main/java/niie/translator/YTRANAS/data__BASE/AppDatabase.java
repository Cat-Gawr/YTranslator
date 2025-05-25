package nie.translator.rtranslator.database;

import androidx.room.RoomDatabase;
import nie.translator.rtranslator.database.dao.MyDao;
import nie.translator.rtranslator.database.entities.RecentPeerEntity;


@androidx.room.Database(version = 1, entities = {RecentPeerEntity.class})
abstract public class AppDatabase extends RoomDatabase {
    abstract public MyDao myDao();
}
