#include "SDL.h"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "dosbox.h"
#include "debug.h"
#include "cpu.h"
#include "video.h"
#include "pic.h"
#include "cpu.h"
#include "callback.h"
#include "inout.h"
#include "mixer.h"
#include "timer.h"
#include "dos_inc.h"
#include "setup.h"
#include "control.h"
#include "cross.h"
#include "programs.h"
#include "support.h"
#include "mapper.h"
#include "ints/int10.h"
#include "render.h"

#include "sdlmain.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void dbTask(void *pvParameters)
{
//    heap_caps_print_heap_info(MALLOC_CAP_SPIRAM);
//    spi_lcd_init();

    char *argv[]={"dosbox", NULL};
    main(1, argv);
}


//extern "C"
extern "C" void app_main(void)
{
	xTaskCreatePinnedToCore(&dbTask, "dbTask", 34000, NULL, 5, NULL, 0);
}