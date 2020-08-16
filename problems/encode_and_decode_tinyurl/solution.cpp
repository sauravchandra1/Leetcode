class Solution {
    public:
        long n = 0;
    unordered_map < int, pair < string, string > > mp;

    string idToShortURL(long n) {
        char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string shorturl;
        while (n) {
            shorturl.push_back(map[n % 62]);
            n = n / 62;
        }
        reverse(shorturl.begin(), shorturl.end());
        return shorturl;
    }

    long shortURLtoID(string shortURL) {
        long id = 0;
        for (int i = 0; i < shortURL.length(); ++i) {
            if ('a' <= shortURL[i] && shortURL[i] <= 'z') {
                id = id * 62 + shortURL[i] - 'a';
            }
            if ('A' <= shortURL[i] && shortURL[i] <= 'Z') {
                id = id * 62 + shortURL[i] - 'A' + 26;
            }
            if ('0' <= shortURL[i] && shortURL[i] <= '9') {
                id = id * 62 + shortURL[i] - '0' + 52;
            }
        }
        return id;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ++n;
        mp[n] = make_pair(longUrl, idToShortURL(n));
        return mp[n].second;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int x = shortURLtoID(shortUrl);
        return mp[x].first;
    }
};