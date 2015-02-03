static const guint16 keymap_xorgevdev2xtkbd[] = {
  [0x9] = 0x1,         /* 9 => 1 via 1 (KEY_ESC) */
  [0xa] = 0x2,         /* 10 => 2 via 2 (KEY_1) */
  [0xb] = 0x3,         /* 11 => 3 via 3 (KEY_2) */
  [0xc] = 0x4,         /* 12 => 4 via 4 (KEY_3) */
  [0xd] = 0x5,         /* 13 => 5 via 5 (KEY_4) */
  [0xe] = 0x6,         /* 14 => 6 via 6 (KEY_5) */
  [0xf] = 0x7,         /* 15 => 7 via 7 (KEY_6) */
  [0x10] = 0x8,        /* 16 => 8 via 8 (KEY_7) */
  [0x11] = 0x9,        /* 17 => 9 via 9 (KEY_8) */
  [0x12] = 0xa,        /* 18 => 10 via 10 (KEY_9) */
  [0x13] = 0xb,        /* 19 => 11 via 11 (KEY_0) */
  [0x14] = 0xc,        /* 20 => 12 via 12 (KEY_MINUS) */
  [0x15] = 0xd,        /* 21 => 13 via 13 (KEY_EQUAL) */
  [0x16] = 0xe,        /* 22 => 14 via 14 (KEY_BACKSPACE) */
  [0x17] = 0xf,        /* 23 => 15 via 15 (KEY_TAB) */
  [0x18] = 0x10,       /* 24 => 16 via 16 (KEY_Q) */
  [0x19] = 0x11,       /* 25 => 17 via 17 (KEY_W) */
  [0x1a] = 0x12,       /* 26 => 18 via 18 (KEY_E) */
  [0x1b] = 0x13,       /* 27 => 19 via 19 (KEY_R) */
  [0x1c] = 0x14,       /* 28 => 20 via 20 (KEY_T) */
  [0x1d] = 0x15,       /* 29 => 21 via 21 (KEY_Y) */
  [0x1e] = 0x16,       /* 30 => 22 via 22 (KEY_U) */
  [0x1f] = 0x17,       /* 31 => 23 via 23 (KEY_I) */
  [0x20] = 0x18,       /* 32 => 24 via 24 (KEY_O) */
  [0x21] = 0x19,       /* 33 => 25 via 25 (KEY_P) */
  [0x22] = 0x1a,       /* 34 => 26 via 26 (KEY_LEFTBRACE) */
  [0x23] = 0x1b,       /* 35 => 27 via 27 (KEY_RIGHTBRACE) */
  [0x24] = 0x1c,       /* 36 => 28 via 28 (KEY_ENTER) */
  [0x25] = 0x1d,       /* 37 => 29 via 29 (KEY_LEFTCTRL) */
  [0x26] = 0x1e,       /* 38 => 30 via 30 (KEY_A) */
  [0x27] = 0x1f,       /* 39 => 31 via 31 (KEY_S) */
  [0x28] = 0x20,       /* 40 => 32 via 32 (KEY_D) */
  [0x29] = 0x21,       /* 41 => 33 via 33 (KEY_F) */
  [0x2a] = 0x22,       /* 42 => 34 via 34 (KEY_G) */
  [0x2b] = 0x23,       /* 43 => 35 via 35 (KEY_H) */
  [0x2c] = 0x24,       /* 44 => 36 via 36 (KEY_J) */
  [0x2d] = 0x25,       /* 45 => 37 via 37 (KEY_K) */
  [0x2e] = 0x26,       /* 46 => 38 via 38 (KEY_L) */
  [0x2f] = 0x27,       /* 47 => 39 via 39 (KEY_SEMICOLON) */
  [0x30] = 0x28,       /* 48 => 40 via 40 (KEY_APOSTROPHE) */
  [0x31] = 0x29,       /* 49 => 41 via 41 (KEY_GRAVE) */
  [0x32] = 0x2a,       /* 50 => 42 via 42 (KEY_LEFTSHIFT) */
  [0x33] = 0x2b,       /* 51 => 43 via 43 (KEY_BACKSLASH) */
  [0x34] = 0x2c,       /* 52 => 44 via 44 (KEY_Z) */
  [0x35] = 0x2d,       /* 53 => 45 via 45 (KEY_X) */
  [0x36] = 0x2e,       /* 54 => 46 via 46 (KEY_C) */
  [0x37] = 0x2f,       /* 55 => 47 via 47 (KEY_V) */
  [0x38] = 0x30,       /* 56 => 48 via 48 (KEY_B) */
  [0x39] = 0x31,       /* 57 => 49 via 49 (KEY_N) */
  [0x3a] = 0x32,       /* 58 => 50 via 50 (KEY_M) */
  [0x3b] = 0x33,       /* 59 => 51 via 51 (KEY_COMMA) */
  [0x3c] = 0x34,       /* 60 => 52 via 52 (KEY_DOT) */
  [0x3d] = 0x35,       /* 61 => 53 via 53 (KEY_SLASH) */
  [0x3e] = 0x36,       /* 62 => 54 via 54 (KEY_RIGHTSHIFT) */
  [0x3f] = 0x37,       /* 63 => 55 via 55 (KEY_KPASTERISK) */
  [0x40] = 0x38,       /* 64 => 56 via 56 (KEY_LEFTALT) */
  [0x41] = 0x39,       /* 65 => 57 via 57 (KEY_SPACE) */
  [0x42] = 0x3a,       /* 66 => 58 via 58 (KEY_CAPSLOCK) */
  [0x43] = 0x3b,       /* 67 => 59 via 59 (KEY_F1) */
  [0x44] = 0x3c,       /* 68 => 60 via 60 (KEY_F2) */
  [0x45] = 0x3d,       /* 69 => 61 via 61 (KEY_F3) */
  [0x46] = 0x3e,       /* 70 => 62 via 62 (KEY_F4) */
  [0x47] = 0x3f,       /* 71 => 63 via 63 (KEY_F5) */
  [0x48] = 0x40,       /* 72 => 64 via 64 (KEY_F6) */
  [0x49] = 0x41,       /* 73 => 65 via 65 (KEY_F7) */
  [0x4a] = 0x42,       /* 74 => 66 via 66 (KEY_F8) */
  [0x4b] = 0x43,       /* 75 => 67 via 67 (KEY_F9) */
  [0x4c] = 0x44,       /* 76 => 68 via 68 (KEY_F10) */
  [0x4d] = 0x45,       /* 77 => 69 via 69 (KEY_NUMLOCK) */
  [0x4e] = 0x46,       /* 78 => 70 via 70 (KEY_SCROLLLOCK) */
  [0x4f] = 0x47,       /* 79 => 71 via 71 (KEY_KP7) */
  [0x50] = 0x48,       /* 80 => 72 via 72 (KEY_KP8) */
  [0x51] = 0x49,       /* 81 => 73 via 73 (KEY_KP9) */
  [0x52] = 0x4a,       /* 82 => 74 via 74 (KEY_KPMINUS) */
  [0x53] = 0x4b,       /* 83 => 75 via 75 (KEY_KP4) */
  [0x54] = 0x4c,       /* 84 => 76 via 76 (KEY_KP5) */
  [0x55] = 0x4d,       /* 85 => 77 via 77 (KEY_KP6) */
  [0x56] = 0x4e,       /* 86 => 78 via 78 (KEY_KPPLUS) */
  [0x57] = 0x4f,       /* 87 => 79 via 79 (KEY_KP1) */
  [0x58] = 0x50,       /* 88 => 80 via 80 (KEY_KP2) */
  [0x59] = 0x51,       /* 89 => 81 via 81 (KEY_KP3) */
  [0x5a] = 0x52,       /* 90 => 82 via 82 (KEY_KP0) */
  [0x5b] = 0x53,       /* 91 => 83 via 83 (KEY_KPDOT) */
  [0x5c] = 0x54,       /* 92 => 84 via 84 */
  [0x5d] = 0x76,       /* 93 => 118 via 85 (KEY_ZENKAKUHANKAKU) */
  [0x5e] = 0x56,       /* 94 => 86 via 86 (KEY_102ND) */
  [0x5f] = 0x57,       /* 95 => 87 via 87 (KEY_F11) */
  [0x60] = 0x58,       /* 96 => 88 via 88 (KEY_F12) */
  [0x61] = 0x73,       /* 97 => 115 via 89 (KEY_RO) */
  [0x62] = 0x78,       /* 98 => 120 via 90 (KEY_KATAKANA) */
  [0x63] = 0x77,       /* 99 => 119 via 91 (KEY_HIRAGANA) */
  [0x64] = 0x79,       /* 100 => 121 via 92 (KEY_HENKAN) */
  [0x65] = 0x70,       /* 101 => 112 via 93 (KEY_KATAKANAHIRAGANA) */
  [0x66] = 0x7b,       /* 102 => 123 via 94 (KEY_MUHENKAN) */
  [0x67] = 0x5c,       /* 103 => 92 via 95 (KEY_KPJPCOMMA) */
  [0x68] = 0x11c,      /* 104 => 284 via 96 (KEY_KPENTER) */
  [0x69] = 0x11d,      /* 105 => 285 via 97 (KEY_RIGHTCTRL) */
  [0x6a] = 0x135,      /* 106 => 309 via 98 (KEY_KPSLASH) */
  [0x6b] = 0x54,       /* 107 => 84 via 99 (KEY_SYSRQ) */
  [0x6c] = 0x138,      /* 108 => 312 via 100 (KEY_RIGHTALT) */
  [0x6d] = 0x5b,       /* 109 => 91 via 101 (KEY_LINEFEED) */
  [0x6e] = 0x147,      /* 110 => 327 via 102 (KEY_HOME) */
  [0x6f] = 0x148,      /* 111 => 328 via 103 (KEY_UP) */
  [0x70] = 0x149,      /* 112 => 329 via 104 (KEY_PAGEUP) */
  [0x71] = 0x14b,      /* 113 => 331 via 105 (KEY_LEFT) */
  [0x72] = 0x14d,      /* 114 => 333 via 106 (KEY_RIGHT) */
  [0x73] = 0x14f,      /* 115 => 335 via 107 (KEY_END) */
  [0x74] = 0x150,      /* 116 => 336 via 108 (KEY_DOWN) */
  [0x75] = 0x151,      /* 117 => 337 via 109 (KEY_PAGEDOWN) */
  [0x76] = 0x152,      /* 118 => 338 via 110 (KEY_INSERT) */
  [0x77] = 0x153,      /* 119 => 339 via 111 (KEY_DELETE) */
  [0x78] = 0x16f,      /* 120 => 367 via 112 (KEY_MACRO) */
  [0x79] = 0x120,      /* 121 => 288 via 113 (KEY_MUTE) */
  [0x7a] = 0x12e,      /* 122 => 302 via 114 (KEY_VOLUMEDOWN) */
  [0x7b] = 0x130,      /* 123 => 304 via 115 (KEY_VOLUMEUP) */
  [0x7c] = 0x15e,      /* 124 => 350 via 116 (KEY_POWER) */
  [0x7d] = 0x59,       /* 125 => 89 via 117 (KEY_KPEQUAL) */
  [0x7e] = 0x14e,      /* 126 => 334 via 118 (KEY_KPPLUSMINUS) */
  [0x7f] = 0x146,      /* 127 => 326 via 119 (KEY_PAUSE) */
  [0x80] = 0x10b,      /* 128 => 267 via 120 (KEY_SCALE) */
  [0x81] = 0x7e,       /* 129 => 126 via 121 (KEY_KPCOMMA) */
  [0x83] = 0x10d,      /* 131 => 269 via 123 (KEY_HANJA) */
  [0x84] = 0x7d,       /* 132 => 125 via 124 (KEY_YEN) */
  [0x85] = 0x15b,      /* 133 => 347 via 125 (KEY_LEFTMETA) */
  [0x86] = 0x15c,      /* 134 => 348 via 126 (KEY_RIGHTMETA) */
  [0x87] = 0x15d,      /* 135 => 349 via 127 (KEY_COMPOSE) */
  [0x88] = 0x168,      /* 136 => 360 via 128 (KEY_STOP) */
  [0x89] = 0x105,      /* 137 => 261 via 129 (KEY_AGAIN) */
  [0x8a] = 0x106,      /* 138 => 262 via 130 (KEY_PROPS) */
  [0x8b] = 0x107,      /* 139 => 263 via 131 (KEY_UNDO) */
  [0x8c] = 0x10c,      /* 140 => 268 via 132 (KEY_FRONT) */
  [0x8d] = 0x178,      /* 141 => 376 via 133 (KEY_COPY) */
  [0x8e] = 0x64,       /* 142 => 100 via 134 (KEY_OPEN) */
  [0x8f] = 0x65,       /* 143 => 101 via 135 (KEY_PASTE) */
  [0x90] = 0x141,      /* 144 => 321 via 136 (KEY_FIND) */
  [0x91] = 0x13c,      /* 145 => 316 via 137 (KEY_CUT) */
  [0x92] = 0x175,      /* 146 => 373 via 138 (KEY_HELP) */
  [0x93] = 0x11e,      /* 147 => 286 via 139 (KEY_MENU) */
  [0x94] = 0x121,      /* 148 => 289 via 140 (KEY_CALC) */
  [0x95] = 0x66,       /* 149 => 102 via 141 (KEY_SETUP) */
  [0x96] = 0x15f,      /* 150 => 351 via 142 (KEY_SLEEP) */
  [0x97] = 0x163,      /* 151 => 355 via 143 (KEY_WAKEUP) */
  [0x98] = 0x67,       /* 152 => 103 via 144 (KEY_FILE) */
  [0x99] = 0x68,       /* 153 => 104 via 145 (KEY_SENDFILE) */
  [0x9a] = 0x69,       /* 154 => 105 via 146 (KEY_DELETEFILE) */
  [0x9b] = 0x113,      /* 155 => 275 via 147 (KEY_XFER) */
  [0x9c] = 0x11f,      /* 156 => 287 via 148 (KEY_PROG1) */
  [0x9d] = 0x117,      /* 157 => 279 via 149 (KEY_PROG2) */
  [0x9e] = 0x102,      /* 158 => 258 via 150 (KEY_WWW) */
  [0x9f] = 0x6a,       /* 159 => 106 via 151 (KEY_MSDOS) */
  [0xa0] = 0x112,      /* 160 => 274 via 152 (KEY_SCREENLOCK) */
  [0xa1] = 0x6b,       /* 161 => 107 via 153 (KEY_DIRECTION) */
  [0xa2] = 0x126,      /* 162 => 294 via 154 (KEY_CYCLEWINDOWS) */
  [0xa3] = 0x16c,      /* 163 => 364 via 155 (KEY_MAIL) */
  [0xa4] = 0x166,      /* 164 => 358 via 156 (KEY_BOOKMARKS) */
  [0xa5] = 0x16b,      /* 165 => 363 via 157 (KEY_COMPUTER) */
  [0xa6] = 0x16a,      /* 166 => 362 via 158 (KEY_BACK) */
  [0xa7] = 0x169,      /* 167 => 361 via 159 (KEY_FORWARD) */
  [0xa8] = 0x123,      /* 168 => 291 via 160 (KEY_CLOSECD) */
  [0xa9] = 0x6c,       /* 169 => 108 via 161 (KEY_EJECTCD) */
  [0xaa] = 0x17d,      /* 170 => 381 via 162 (KEY_EJECTCLOSECD) */
  [0xab] = 0x119,      /* 171 => 281 via 163 (KEY_NEXTSONG) */
  [0xac] = 0x122,      /* 172 => 290 via 164 (KEY_PLAYPAUSE) */
  [0xad] = 0x110,      /* 173 => 272 via 165 (KEY_PREVIOUSSONG) */
  [0xae] = 0x124,      /* 174 => 292 via 166 (KEY_STOPCD) */
  [0xaf] = 0x131,      /* 175 => 305 via 167 (KEY_RECORD) */
  [0xb0] = 0x118,      /* 176 => 280 via 168 (KEY_REWIND) */
  [0xb1] = 0x63,       /* 177 => 99 via 169 (KEY_PHONE) */
  [0xb2] = 0x70,       /* 178 => 112 via 170 (KEY_ISO) */
  [0xb3] = 0x101,      /* 179 => 257 via 171 (KEY_CONFIG) */
  [0xb4] = 0x132,      /* 180 => 306 via 172 (KEY_HOMEPAGE) */
  [0xb5] = 0x167,      /* 181 => 359 via 173 (KEY_REFRESH) */
  [0xb6] = 0x71,       /* 182 => 113 via 174 (KEY_EXIT) */
  [0xb7] = 0x72,       /* 183 => 114 via 175 (KEY_MOVE) */
  [0xb8] = 0x108,      /* 184 => 264 via 176 (KEY_EDIT) */
  [0xb9] = 0x75,       /* 185 => 117 via 177 (KEY_SCROLLUP) */
  [0xba] = 0x10f,      /* 186 => 271 via 178 (KEY_SCROLLDOWN) */
  [0xbb] = 0x176,      /* 187 => 374 via 179 (KEY_KPLEFTPAREN) */
  [0xbc] = 0x17b,      /* 188 => 379 via 180 (KEY_KPRIGHTPAREN) */
  [0xbd] = 0x109,      /* 189 => 265 via 181 (KEY_NEW) */
  [0xbe] = 0x10a,      /* 190 => 266 via 182 (KEY_REDO) */
  [0xbf] = 0x5d,       /* 191 => 93 via 183 (KEY_F13) */
  [0xc0] = 0x5e,       /* 192 => 94 via 184 (KEY_F14) */
  [0xc1] = 0x5f,       /* 193 => 95 via 185 (KEY_F15) */
  [0xc2] = 0x55,       /* 194 => 85 via 186 (KEY_F16) */
  [0xc3] = 0x103,      /* 195 => 259 via 187 (KEY_F17) */
  [0xc4] = 0x177,      /* 196 => 375 via 188 (KEY_F18) */
  [0xc5] = 0x104,      /* 197 => 260 via 189 (KEY_F19) */
  [0xc6] = 0x5a,       /* 198 => 90 via 190 (KEY_F20) */
  [0xc7] = 0x74,       /* 199 => 116 via 191 (KEY_F21) */
  [0xc8] = 0x179,      /* 200 => 377 via 192 (KEY_F22) */
  [0xc9] = 0x6d,       /* 201 => 109 via 193 (KEY_F23) */
  [0xca] = 0x6f,       /* 202 => 111 via 194 (KEY_F24) */
  [0xcb] = 0x115,      /* 203 => 277 via 195 */
  [0xcc] = 0x116,      /* 204 => 278 via 196 */
  [0xcd] = 0x11a,      /* 205 => 282 via 197 */
  [0xce] = 0x11b,      /* 206 => 283 via 198 */
  [0xcf] = 0x127,      /* 207 => 295 via 199 */
  [0xd0] = 0x128,      /* 208 => 296 via 200 (KEY_PLAYCD) */
  [0xd1] = 0x129,      /* 209 => 297 via 201 (KEY_PAUSECD) */
  [0xd2] = 0x12b,      /* 210 => 299 via 202 (KEY_PROG3) */
  [0xd3] = 0x12c,      /* 211 => 300 via 203 (KEY_PROG4) */
  [0xd4] = 0x12d,      /* 212 => 301 via 204 (KEY_DASHBOARD) */
  [0xd5] = 0x125,      /* 213 => 293 via 205 (KEY_SUSPEND) */
  [0xd6] = 0x12f,      /* 214 => 303 via 206 (KEY_CLOSE) */
  [0xd7] = 0x133,      /* 215 => 307 via 207 (KEY_PLAY) */
  [0xd8] = 0x134,      /* 216 => 308 via 208 (KEY_FASTFORWARD) */
  [0xd9] = 0x136,      /* 217 => 310 via 209 (KEY_BASSBOOST) */
  [0xda] = 0x139,      /* 218 => 313 via 210 (KEY_PRINT) */
  [0xdb] = 0x13a,      /* 219 => 314 via 211 (KEY_HP) */
  [0xdc] = 0x13b,      /* 220 => 315 via 212 (KEY_CAMERA) */
  [0xdd] = 0x13d,      /* 221 => 317 via 213 (KEY_SOUND) */
  [0xde] = 0x13e,      /* 222 => 318 via 214 (KEY_QUESTION) */
  [0xdf] = 0x13f,      /* 223 => 319 via 215 (KEY_EMAIL) */
  [0xe0] = 0x140,      /* 224 => 320 via 216 (KEY_CHAT) */
  [0xe1] = 0x165,      /* 225 => 357 via 217 (KEY_SEARCH) */
  [0xe2] = 0x142,      /* 226 => 322 via 218 (KEY_CONNECT) */
  [0xe3] = 0x143,      /* 227 => 323 via 219 (KEY_FINANCE) */
  [0xe4] = 0x144,      /* 228 => 324 via 220 (KEY_SPORT) */
  [0xe5] = 0x145,      /* 229 => 325 via 221 (KEY_SHOP) */
  [0xe6] = 0x114,      /* 230 => 276 via 222 (KEY_ALTERASE) */
  [0xe7] = 0x14a,      /* 231 => 330 via 223 (KEY_CANCEL) */
  [0xe8] = 0x14c,      /* 232 => 332 via 224 (KEY_BRIGHTNESSDOWN) */
  [0xe9] = 0x154,      /* 233 => 340 via 225 (KEY_BRIGHTNESSUP) */
  [0xea] = 0x16d,      /* 234 => 365 via 226 (KEY_MEDIA) */
  [0xeb] = 0x156,      /* 235 => 342 via 227 (KEY_SWITCHVIDEOMODE) */
  [0xec] = 0x157,      /* 236 => 343 via 228 (KEY_KBDILLUMTOGGLE) */
  [0xed] = 0x158,      /* 237 => 344 via 229 (KEY_KBDILLUMDOWN) */
  [0xee] = 0x159,      /* 238 => 345 via 230 (KEY_KBDILLUMUP) */
  [0xef] = 0x15a,      /* 239 => 346 via 231 (KEY_SEND) */
  [0xf0] = 0x164,      /* 240 => 356 via 232 (KEY_REPLY) */
  [0xf1] = 0x10e,      /* 241 => 270 via 233 (KEY_FORWARDMAIL) */
  [0xf2] = 0x155,      /* 242 => 341 via 234 (KEY_SAVE) */
  [0xf3] = 0x170,      /* 243 => 368 via 235 (KEY_DOCUMENTS) */
  [0xf4] = 0x171,      /* 244 => 369 via 236 (KEY_BATTERY) */
  [0xf5] = 0x172,      /* 245 => 370 via 237 (KEY_BLUETOOTH) */
  [0xf6] = 0x173,      /* 246 => 371 via 238 (KEY_WLAN) */
  [0xf7] = 0x174,      /* 247 => 372 via 239 (KEY_UWB) */
};
