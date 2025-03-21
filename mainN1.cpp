#include "1.h"

#include <iostream>

int main()
{
    // ������ ����� ��� ����������
    unsigned char key[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    int keyLength = sizeof(key);

    // ������� ������ Encoder � ������
    encoder encoder(key, keyLength);

    // ���������� ���������� �����
    encoder.encode("example.txt", "example_encrypted.txt", true);
    std::cout << "Text file encrypted." << std::endl;

    // ������������ ���������� �����
    encoder.encode("example_encrypted.txt", "example_decrypted.txt", false);
    std::cout << "Text file decrypted." << std::endl;

    // ���������� ������������ �����
    encoder.encode("image.jpg", "image_encrypted.jpg", true);
    std::cout << "Image file encrypted." << std::endl;

    // ������������ ������������ �����
    encoder.encode("image_encrypted.jpg", "image_decrypted.jpg", false);
    std::cout << "Image file decrypted." << std::endl;

    // ���������� ����� �����
    encoder.encode("audio.mp3", "audio_encrypted.mp3", true);
    std::cout << "Audio file encrypted." << std::endl;

    // ������������ ����� �����
    encoder.encode("audio_encrypted.mp3", "audio_decrypted.mp3", false);
    std::cout << "Audio file decrypted." << std::endl;

    // ���������� ����� �����
    encoder.encode("video.mp4", "video_encrypted.mp4", true);
    std::cout << "Video file encrypted." << std::endl;

    // ������������ ����� �����
    encoder.encode("video_encrypted.mp4", "video_decrypted.mp4", false);
    std::cout << "Video file decrypted." << std::endl;

    // ���������� ������������ �����
    encoder.encode("program.exe", "program_encrypted.exe", true);
    std::cout << "Executable file encrypted." << std::endl;

    // ������������ ������������ �����
    encoder.encode("program_encrypted.exe", "program_decrypted.exe", false);
    std::cout << "Executable file decrypted." << std::endl;

    return 0;
}