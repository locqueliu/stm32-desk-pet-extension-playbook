# Upstream Reference

## Confirmed Source

- upstream project: [Sngels_wyh / STM32 Smart Desktop Pet](https://oshwhub.com/sngelswyh/stm32-smart-desktop-pet)
- platform: `OSHWHub`
- public article reference: [CSDN article](https://blog.csdn.net/2402_83438920/article/details/145213286)
- observed license: `GPL 3.0`

## Evidence Used For Attribution

The local project header comment in `User/main.c` points to the OSHWHub URL above and describes the project as an STM32F103C8T6-based desktop pet updated on `2025-02-16`.

That makes the upstream reference explicit enough to cite before any public portfolio publication.

## Why A Documentation Repo Is Safer

The local working tree contains private modifications and compiled artifacts. Publishing that code directly would create avoidable risk:

- unclear separation between upstream and local changes
- possible leakage of private files or build output
- derivative publication obligations under GPL

So this repository only keeps clean-room explanations and extension notes.
