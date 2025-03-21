#include "1.h"

#include <iostream>

int main()
{
    // Пример ключа для шифрования
    unsigned char key[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    int keyLength = sizeof(key);

    // Создаем объект Encoder с ключом
    encoder encoder(key, keyLength);

    // Шифрование текстового файла
    encoder.encode("example.txt", "example_encrypted.txt", true);
    std::cout << "Text file encrypted." << std::endl;

    // Дешифрование текстового файла
    encoder.encode("example_encrypted.txt", "example_decrypted.txt", false);
    std::cout << "Text file decrypted." << std::endl;

    // Шифрование графического файла
    encoder.encode("image.jpg", "image_encrypted.jpg", true);
    std::cout << "Image file encrypted." << std::endl;

    // Дешифрование графического файла
    encoder.encode("image_encrypted.jpg", "image_decrypted.jpg", false);
    std::cout << "Image file decrypted." << std::endl;

    // Шифрование аудио файла
    encoder.encode("audio.mp3", "audio_encrypted.mp3", true);
    std::cout << "Audio file encrypted." << std::endl;

    // Дешифрование аудио файла
    encoder.encode("audio_encrypted.mp3", "audio_decrypted.mp3", false);
    std::cout << "Audio file decrypted." << std::endl;

    // Шифрование видео файла
    encoder.encode("video.mp4", "video_encrypted.mp4", true);
    std::cout << "Video file encrypted." << std::endl;

    // Дешифрование видео файла
    encoder.encode("video_encrypted.mp4", "video_decrypted.mp4", false);
    std::cout << "Video file decrypted." << std::endl;

    // Шифрование исполняемого файла
    encoder.encode("program.exe", "program_encrypted.exe", true);
    std::cout << "Executable file encrypted." << std::endl;

    // Дешифрование исполняемого файла
    encoder.encode("program_encrypted.exe", "program_decrypted.exe", false);
    std::cout << "Executable file decrypted." << std::endl;

    return 0;
}