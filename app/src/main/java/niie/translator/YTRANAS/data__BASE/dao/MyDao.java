package nie.translator.rtranslator.database.dao;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.Query;
import androidx.room.Update;
import nie.translator.rtranslator.database.entities.RecentPeerEntity;

@Dao
public interface MyDao{
    //inserts
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    void insertRecentPeers(RecentPeerEntity... recentPeerEntities);

    //updates
    @Update
    void updateRecentPeers(RecentPeerEntity... recentPeerEntities);

    //deletes
    @Delete
    void deleteRecentPeers(RecentPeerEntity... recentPeerEntities);

    //select
    @Query("SELECT * FROM RecentPeerEntity")
    RecentPeerEntity[] loadRecentPeers();

    @Query("SELECT * FROM RecentPeerEntity where deviceId=:deviceId")
    RecentPeerEntity loadRecentPeer(String deviceId);

    @Query("SELECT * FROM RecentPeerEntity where uniqueName=:uniqueName")
    RecentPeerEntity loadRecentPeerByName(String uniqueName);

}
