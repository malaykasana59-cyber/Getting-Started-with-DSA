// String Hashing - Learning Notes
//
// Hashing converts a string into a numeric value called a hash value. It is
// useful for comparing strings, searching efficiently, detecting duplicates,
// grouping anagrams, and solving pattern-matching problems.
//
// Why hashing is useful:
// 1. Efficient comparisons:
//    Comparing large strings character by character can be slow. Comparing
//    their hash values is usually constant time after preprocessing.
// 2. Faster lookups:
//    Hash tables such as unordered_map and unordered_set use hash values for
//    average O(1) insertion and lookup.
// 3. Duplicate and anagram detection:
//    Hash values or frequency-based hashes can help group equal strings and
//    anagrams efficiently.
// 4. Pattern matching:
//    Algorithms such as Rabin-Karp use rolling hashes to search substrings.
//
// Polynomial rolling hash:
//
// Hash(s) = (s[0] * p^0 + s[1] * p^1 + ... + s[n-1] * p^(n-1)) % m
//
// Here:
// - s[i] is the numeric value of the character at index i.
// - Characters can be mapped as 'a' = 1, 'b' = 2, and so on.
// - p is a prime base, commonly 31 or 53.
// - m is a large prime modulus, commonly 1e9 + 7 or 1e9 + 9.
// - The modulus keeps values small and helps reduce overflow.
//
// Example: hash of "abc"
//
// Map a = 1, b = 2, c = 3, choose p = 31 and m = 1e9 + 9:
// Hash("abc") = (1 * 31^0 + 2 * 31^1 + 3 * 31^2) % (1e9 + 9)
//             = (1 + 62 + 2883) % (1e9 + 9)
//             = 2946
//
// Collisions:
// Two different strings can produce the same hash value. This is called a
// collision. A collision cannot be eliminated completely with one hash, but
// its probability can be reduced by:
// - choosing a large modulus;
// - choosing a suitable prime base;
// - using two independent hash functions (double hashing);
// - verifying the actual characters when a hash match is found.
//
// A rolling hash updates the hash of a sliding substring without rebuilding
// it from the beginning. With suitable prefix hashes, substring hashes can
// be queried in O(1) after O(n) preprocessing.
