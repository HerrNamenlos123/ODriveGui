
#include "pch.h"
#include "CRC.h"

// CRC8 Table

uint8_t CRC8(uint8_t* data, size_t len) {
    uint8_t crc = 0x42;
    static const uint8_t table[] = {
      0x00, 0x37, 0x6E, 0x59, 0xDC, 0xEB, 0xB2, 0x85, 0x8F, 0xB8, 0xE1, 0xD6, 0x53, 0x64, 0x3D, 0x0A,
      0x29, 0x1E, 0x47, 0x70, 0xF5, 0xC2, 0x9B, 0xAC, 0xA6, 0x91, 0xC8, 0xFF, 0x7A, 0x4D, 0x14, 0x23,
      0x52, 0x65, 0x3C, 0x0B, 0x8E, 0xB9, 0xE0, 0xD7, 0xDD, 0xEA, 0xB3, 0x84, 0x01, 0x36, 0x6F, 0x58,
      0x7B, 0x4C, 0x15, 0x22, 0xA7, 0x90, 0xC9, 0xFE, 0xF4, 0xC3, 0x9A, 0xAD, 0x28, 0x1F, 0x46, 0x71,
      0xA4, 0x93, 0xCA, 0xFD, 0x78, 0x4F, 0x16, 0x21, 0x2B, 0x1C, 0x45, 0x72, 0xF7, 0xC0, 0x99, 0xAE,
      0x8D, 0xBA, 0xE3, 0xD4, 0x51, 0x66, 0x3F, 0x08, 0x02, 0x35, 0x6C, 0x5B, 0xDE, 0xE9, 0xB0, 0x87,
      0xF6, 0xC1, 0x98, 0xAF, 0x2A, 0x1D, 0x44, 0x73, 0x79, 0x4E, 0x17, 0x20, 0xA5, 0x92, 0xCB, 0xFC,
      0xDF, 0xE8, 0xB1, 0x86, 0x03, 0x34, 0x6D, 0x5A, 0x50, 0x67, 0x3E, 0x09, 0x8C, 0xBB, 0xE2, 0xD5,
      0x7F, 0x48, 0x11, 0x26, 0xA3, 0x94, 0xCD, 0xFA, 0xF0, 0xC7, 0x9E, 0xA9, 0x2C, 0x1B, 0x42, 0x75,
      0x56, 0x61, 0x38, 0x0F, 0x8A, 0xBD, 0xE4, 0xD3, 0xD9, 0xEE, 0xB7, 0x80, 0x05, 0x32, 0x6B, 0x5C,
      0x2D, 0x1A, 0x43, 0x74, 0xF1, 0xC6, 0x9F, 0xA8, 0xA2, 0x95, 0xCC, 0xFB, 0x7E, 0x49, 0x10, 0x27,
      0x04, 0x33, 0x6A, 0x5D, 0xD8, 0xEF, 0xB6, 0x81, 0x8B, 0xBC, 0xE5, 0xD2, 0x57, 0x60, 0x39, 0x0E,
      0xDB, 0xEC, 0xB5, 0x82, 0x07, 0x30, 0x69, 0x5E, 0x54, 0x63, 0x3A, 0x0D, 0x88, 0xBF, 0xE6, 0xD1,
      0xF2, 0xC5, 0x9C, 0xAB, 0x2E, 0x19, 0x40, 0x77, 0x7D, 0x4A, 0x13, 0x24, 0xA1, 0x96, 0xCF, 0xF8,
      0x89, 0xBE, 0xE7, 0xD0, 0x55, 0x62, 0x3B, 0x0C, 0x06, 0x31, 0x68, 0x5F, 0xDA, 0xED, 0xB4, 0x83,
      0xA0, 0x97, 0xCE, 0xF9, 0x7C, 0x4B, 0x12, 0x25, 0x2F, 0x18, 0x41, 0x76, 0xF3, 0xC4, 0x9D, 0xAA
    };

    if (data == NULL)
        return 0xff;

    crc &= 0xff;
    while (len--)
        crc = table[crc ^ *data++];

    return crc;
}

// CRC16 Table

uint16_t CRC16(uint8_t* data, size_t len) {
    uint16_t crc = 0x1337;
    static const uint16_t table[] = {
      0x0000, 0x3D65, 0x7ACA, 0x47AF, 0xF594, 0xC8F1, 0x8F5E, 0xB23B, 0xD64D, 0xEB28, 0xAC87, 0x91E2, 0x23D9, 0x1EBC, 0x5913, 0x6476,
      0x91FF, 0xAC9A, 0xEB35, 0xD650, 0x646B, 0x590E, 0x1EA1, 0x23C4, 0x47B2, 0x7AD7, 0x3D78, 0x001D, 0xB226, 0x8F43, 0xC8EC, 0xF589,
      0x1E9B, 0x23FE, 0x6451, 0x5934, 0xEB0F, 0xD66A, 0x91C5, 0xACA0, 0xC8D6, 0xF5B3, 0xB21C, 0x8F79, 0x3D42, 0x0027, 0x4788, 0x7AED,
      0x8F64, 0xB201, 0xF5AE, 0xC8CB, 0x7AF0, 0x4795, 0x003A, 0x3D5F, 0x5929, 0x644C, 0x23E3, 0x1E86, 0xACBD, 0x91D8, 0xD677, 0xEB12,
      0x3D36, 0x0053, 0x47FC, 0x7A99, 0xC8A2, 0xF5C7, 0xB268, 0x8F0D, 0xEB7B, 0xD61E, 0x91B1, 0xACD4, 0x1EEF, 0x238A, 0x6425, 0x5940,
      0xACC9, 0x91AC, 0xD603, 0xEB66, 0x595D, 0x6438, 0x2397, 0x1EF2, 0x7A84, 0x47E1, 0x004E, 0x3D2B, 0x8F10, 0xB275, 0xF5DA, 0xC8BF,
      0x23AD, 0x1EC8, 0x5967, 0x6402, 0xD639, 0xEB5C, 0xACF3, 0x9196, 0xF5E0, 0xC885, 0x8F2A, 0xB24F, 0x0074, 0x3D11, 0x7ABE, 0x47DB,
      0xB252, 0x8F37, 0xC898, 0xF5FD, 0x47C6, 0x7AA3, 0x3D0C, 0x0069, 0x641F, 0x597A, 0x1ED5, 0x23B0, 0x918B, 0xACEE, 0xEB41, 0xD624,
      0x7A6C, 0x4709, 0x00A6, 0x3DC3, 0x8FF8, 0xB29D, 0xF532, 0xC857, 0xAC21, 0x9144, 0xD6EB, 0xEB8E, 0x59B5, 0x64D0, 0x237F, 0x1E1A,
      0xEB93, 0xD6F6, 0x9159, 0xAC3C, 0x1E07, 0x2362, 0x64CD, 0x59A8, 0x3DDE, 0x00BB, 0x4714, 0x7A71, 0xC84A, 0xF52F, 0xB280, 0x8FE5,
      0x64F7, 0x5992, 0x1E3D, 0x2358, 0x9163, 0xAC06, 0xEBA9, 0xD6CC, 0xB2BA, 0x8FDF, 0xC870, 0xF515, 0x472E, 0x7A4B, 0x3DE4, 0x0081,
      0xF508, 0xC86D, 0x8FC2, 0xB2A7, 0x009C, 0x3DF9, 0x7A56, 0x4733, 0x2345, 0x1E20, 0x598F, 0x64EA, 0xD6D1, 0xEBB4, 0xAC1B, 0x917E,
      0x475A, 0x7A3F, 0x3D90, 0x00F5, 0xB2CE, 0x8FAB, 0xC804, 0xF561, 0x9117, 0xAC72, 0xEBDD, 0xD6B8, 0x6483, 0x59E6, 0x1E49, 0x232C,
      0xD6A5, 0xEBC0, 0xAC6F, 0x910A, 0x2331, 0x1E54, 0x59FB, 0x649E, 0x00E8, 0x3D8D, 0x7A22, 0x4747, 0xF57C, 0xC819, 0x8FB6, 0xB2D3,
      0x59C1, 0x64A4, 0x230B, 0x1E6E, 0xAC55, 0x9130, 0xD69F, 0xEBFA, 0x8F8C, 0xB2E9, 0xF546, 0xC823, 0x7A18, 0x477D, 0x00D2, 0x3DB7,
      0xC83E, 0xF55B, 0xB2F4, 0x8F91, 0x3DAA, 0x00CF, 0x4760, 0x7A05, 0x1E73, 0x2316, 0x64B9, 0x59DC, 0xEBE7, 0xD682, 0x912D, 0xAC48
    };

    if (data == NULL)
        return 0xffff;

    crc &= 0xffff;
    while (len--)
        crc = (crc << 8) ^ table[((crc >> 8) ^ *data++)];

    return crc;
}

uint16_t CRC16_JSON(uint8_t* data, size_t len) {
    uint16_t crc = 1;
    static const uint16_t table[] = {
      0x0000, 0x3D65, 0x7ACA, 0x47AF, 0xF594, 0xC8F1, 0x8F5E, 0xB23B, 0xD64D, 0xEB28, 0xAC87, 0x91E2, 0x23D9, 0x1EBC, 0x5913, 0x6476,
      0x91FF, 0xAC9A, 0xEB35, 0xD650, 0x646B, 0x590E, 0x1EA1, 0x23C4, 0x47B2, 0x7AD7, 0x3D78, 0x001D, 0xB226, 0x8F43, 0xC8EC, 0xF589,
      0x1E9B, 0x23FE, 0x6451, 0x5934, 0xEB0F, 0xD66A, 0x91C5, 0xACA0, 0xC8D6, 0xF5B3, 0xB21C, 0x8F79, 0x3D42, 0x0027, 0x4788, 0x7AED,
      0x8F64, 0xB201, 0xF5AE, 0xC8CB, 0x7AF0, 0x4795, 0x003A, 0x3D5F, 0x5929, 0x644C, 0x23E3, 0x1E86, 0xACBD, 0x91D8, 0xD677, 0xEB12,
      0x3D36, 0x0053, 0x47FC, 0x7A99, 0xC8A2, 0xF5C7, 0xB268, 0x8F0D, 0xEB7B, 0xD61E, 0x91B1, 0xACD4, 0x1EEF, 0x238A, 0x6425, 0x5940,
      0xACC9, 0x91AC, 0xD603, 0xEB66, 0x595D, 0x6438, 0x2397, 0x1EF2, 0x7A84, 0x47E1, 0x004E, 0x3D2B, 0x8F10, 0xB275, 0xF5DA, 0xC8BF,
      0x23AD, 0x1EC8, 0x5967, 0x6402, 0xD639, 0xEB5C, 0xACF3, 0x9196, 0xF5E0, 0xC885, 0x8F2A, 0xB24F, 0x0074, 0x3D11, 0x7ABE, 0x47DB,
      0xB252, 0x8F37, 0xC898, 0xF5FD, 0x47C6, 0x7AA3, 0x3D0C, 0x0069, 0x641F, 0x597A, 0x1ED5, 0x23B0, 0x918B, 0xACEE, 0xEB41, 0xD624,
      0x7A6C, 0x4709, 0x00A6, 0x3DC3, 0x8FF8, 0xB29D, 0xF532, 0xC857, 0xAC21, 0x9144, 0xD6EB, 0xEB8E, 0x59B5, 0x64D0, 0x237F, 0x1E1A,
      0xEB93, 0xD6F6, 0x9159, 0xAC3C, 0x1E07, 0x2362, 0x64CD, 0x59A8, 0x3DDE, 0x00BB, 0x4714, 0x7A71, 0xC84A, 0xF52F, 0xB280, 0x8FE5,
      0x64F7, 0x5992, 0x1E3D, 0x2358, 0x9163, 0xAC06, 0xEBA9, 0xD6CC, 0xB2BA, 0x8FDF, 0xC870, 0xF515, 0x472E, 0x7A4B, 0x3DE4, 0x0081,
      0xF508, 0xC86D, 0x8FC2, 0xB2A7, 0x009C, 0x3DF9, 0x7A56, 0x4733, 0x2345, 0x1E20, 0x598F, 0x64EA, 0xD6D1, 0xEBB4, 0xAC1B, 0x917E,
      0x475A, 0x7A3F, 0x3D90, 0x00F5, 0xB2CE, 0x8FAB, 0xC804, 0xF561, 0x9117, 0xAC72, 0xEBDD, 0xD6B8, 0x6483, 0x59E6, 0x1E49, 0x232C,
      0xD6A5, 0xEBC0, 0xAC6F, 0x910A, 0x2331, 0x1E54, 0x59FB, 0x649E, 0x00E8, 0x3D8D, 0x7A22, 0x4747, 0xF57C, 0xC819, 0x8FB6, 0xB2D3,
      0x59C1, 0x64A4, 0x230B, 0x1E6E, 0xAC55, 0x9130, 0xD69F, 0xEBFA, 0x8F8C, 0xB2E9, 0xF546, 0xC823, 0x7A18, 0x477D, 0x00D2, 0x3DB7,
      0xC83E, 0xF55B, 0xB2F4, 0x8F91, 0x3DAA, 0x00CF, 0x4760, 0x7A05, 0x1E73, 0x2316, 0x64B9, 0x59DC, 0xEBE7, 0xD682, 0x912D, 0xAC48
    };

    if (data == NULL)
        return 0xffff;

    crc &= 0xffff;
    while (len--)
        crc = (crc << 8) ^ table[((crc >> 8) ^ *data++)];

    return crc;
}
