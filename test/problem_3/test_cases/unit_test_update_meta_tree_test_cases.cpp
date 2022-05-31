#include "../unit_test_merkle_kv.h"

void update_meta_tree_test_cases(std::vector<MerkleKVMetaTestCase> &test_cases) {
    test_cases = {
            {
                    {
                            {"x",  "1"},
                    },
                    {"6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b"}
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                    },
                    {"6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b",
                            "d4735e3a265e16eee03f59718b9b5d03019c07d8b6c51f90da3a666eec13ab35",
                            "33b675636da5dcc86ec847b38c08fa49ff1cace9749931e0a5d4dfdbdedd808a"}
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                    },
                    {"6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b",
                            "d4735e3a265e16eee03f59718b9b5d03019c07d8b6c51f90da3a666eec13ab35",
                            "4e07408562bedb8b60ce05c1decfe3ad16b72230967de01f640b7e4729b49fce",
                            "4b227777d4dd1fc61c6f884f48641d02b4d121d3fd328cb08b5531fcacdabf8a",

                            "33b675636da5dcc86ec847b38c08fa49ff1cace9749931e0a5d4dfdbdedd808a",
                            "13656c83d841ea7de6ebf3a89e0038fea9526bd7f686f06f7a692343a8a32dca",

                            "85df8945419d2b5038f7ac83ec1ec6b8267c40fdb3b1e56ff62f6676eb855e70"}
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {"6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b",
                            "d4735e3a265e16eee03f59718b9b5d03019c07d8b6c51f90da3a666eec13ab35",
                            "4e07408562bedb8b60ce05c1decfe3ad16b72230967de01f640b7e4729b49fce",
                            "4b227777d4dd1fc61c6f884f48641d02b4d121d3fd328cb08b5531fcacdabf8a",
                            "ef2d127de37b942baad06145e54b0c619a1f22327b2ebbcfbec78f5564afe39d",
                            "e7f6c011776e8db7cd330b54174fd76f7d0216b612387a5ffcfb81e6f0919683",
                            "7902699be42c8a8e46fbbb4501726517e86b22c56a189f7625a6da49081b2451",
                            "2c624232cdd221771294dfbb310aca000a0df6ac8b66b696d90ef06fdefb64a3",

                            "33b675636da5dcc86ec847b38c08fa49ff1cace9749931e0a5d4dfdbdedd808a",
                            "13656c83d841ea7de6ebf3a89e0038fea9526bd7f686f06f7a692343a8a32dca",
                            "43587f59c00a8e528bc7636fabaffcf70cc25afc5b4d53df797faf0dc72f6dd0",
                            "ada17dcc2d615cc0d982a538b618f45441e798c38b1df9f3dd273e386eba1363",

                            "85df8945419d2b5038f7ac83ec1ec6b8267c40fdb3b1e56ff62f6676eb855e70",
                            "e0e2d0cec0ef7e8fc458e516dfde82890c183431a3f9efae9e4693fc23dfa36a",

                            "c27450cd3fd4df029145f3437ae9c381e0ae55e8400de06cb973005b36d7b222"}
            },
    };
}