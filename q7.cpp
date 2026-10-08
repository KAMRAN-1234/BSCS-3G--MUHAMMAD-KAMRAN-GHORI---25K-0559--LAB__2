#include <iostream>
using namespace std;

class PlaylistManager {
private:
    int** playlists;
    int* playlistSizes;
    int playlistCount;

public:
    PlaylistManager(int count) {
        playlistCount = count;
        playlists = new int*[playlistCount];
        playlistSizes = new int[playlistCount];

        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            cout << "Enter number of tracks in playlist " << playlistIndex << ": ";
            cin >> playlistSizes[playlistIndex];

            playlists[playlistIndex] = new int[playlistSizes[playlistIndex]];
            cout << "Enter track IDs: ";
            for (int trackIndex = 0; trackIndex < playlistSizes[playlistIndex]; ++trackIndex) {
                cin >> playlists[playlistIndex][trackIndex];
            }
        }
    }

    PlaylistManager(const PlaylistManager& other) {
        playlistCount = other.playlistCount;
        playlists = new int*[playlistCount];
        playlistSizes = new int[playlistCount];

        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            playlistSizes[playlistIndex] = other.playlistSizes[playlistIndex];
            playlists[playlistIndex] = new int[playlistSizes[playlistIndex]];

            for (int trackIndex = 0; trackIndex < playlistSizes[playlistIndex]; ++trackIndex) {
                playlists[playlistIndex][trackIndex] = other.playlists[playlistIndex][trackIndex];
            }
        }

        cout << "Deep copy created successfully!\n";
    }

    void addTrack(int playlistIndex, int trackId) {
        if (playlistIndex < 0 || playlistIndex >= playlistCount) {
            cout << "Invalid playlist!\n";
            return;
        }

        int oldSize = playlistSizes[playlistIndex];
        int* updatedPlaylist = new int[oldSize + 1];

        for (int index = 0; index < oldSize; ++index) {
            updatedPlaylist[index] = playlists[playlistIndex][index];
        }

        updatedPlaylist[oldSize] = trackId;
        delete[] playlists[playlistIndex];
        playlists[playlistIndex] = updatedPlaylist;
        ++playlistSizes[playlistIndex];

        cout << "Track added successfully!\n";
    }

    void play(int playlistIndex, int trackIndex) {
        if (playlistIndex < 0 || playlistIndex >= playlistCount) {
            cout << "Invalid playlist!\n";
            return;
        }
        if (trackIndex < 0 || trackIndex >= playlistSizes[playlistIndex]) {
            cout << "Invalid track!\n";
            return;
        }

        cout << "Playing track ID: " << playlists[playlistIndex][trackIndex] << endl;
    }

    void show() const {
        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            cout << "Playlist " << playlistIndex << ": ";
            for (int trackIndex = 0; trackIndex < playlistSizes[playlistIndex]; ++trackIndex) {
                cout << playlists[playlistIndex][trackIndex] << ' ';
            }
            cout << endl;
        }
    }

    ~PlaylistManager() {
        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            delete[] playlists[playlistIndex];
        }
        delete[] playlists;
        delete[] playlistSizes;
    }
};

int main() {
    int playlistCount;
    cout << "Enter number of playlists: ";
    cin >> playlistCount;

    PlaylistManager original(playlistCount);
    cout << "\nOriginal playlists:\n";
    original.show();

    PlaylistManager copy = original;
    cout << "\nCopied playlists:\n";
    copy.show();

    int playlistIndex;
    int trackId;
    cout << "\nEnter playlist to add track to copy: ";
    cin >> playlistIndex;
    cout << "Enter track ID: ";
    cin >> trackId;

    copy.addTrack(playlistIndex, trackId);

    cout << "\nOriginal after modifying copy:\n";
    original.show();
    cout << "\nCopy after modification:\n";
    copy.show();

    cout << "\nTesting track access:\n";
    copy.play(0, 0);

    return 0;
}