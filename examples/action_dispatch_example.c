#include <stddef.h>
#include <stdint.h>

typedef void (*action_handler_t)(void);

typedef struct {
    uint8_t command;
    action_handler_t handler;
} action_entry_t;

void HandleRelaxed(void);
void HandleSit(void);
void HandleUpright(void);
void HandleAdvance(void);
void HandleHello(void);

static const action_entry_t kActionTable[] = {
    {0x29, HandleRelaxed},
    {0x30, HandleSit},
    {0x31, HandleUpright},
    {0x33, HandleAdvance},
    {0x43, HandleHello},
};

action_handler_t ResolveActionHandler(uint8_t command) {
    size_t count = sizeof(kActionTable) / sizeof(kActionTable[0]);
    for (size_t i = 0; i < count; ++i) {
        if (kActionTable[i].command == command) {
            return kActionTable[i].handler;
        }
    }

    return NULL;
}
