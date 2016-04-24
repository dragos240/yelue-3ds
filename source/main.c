#include <3ds.h>
#include <sf2d.h>

#define CONFIG_3D_SLIDERSTATE (*(float *)0x1FF81080)

int main()
{
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_3D(1);

	float offset3d = 0.0f;
	u32 held;

	while (aptMainLoop()) {

		hidScanInput();
		held = hidKeysHeld();

		if (held & KEY_START) {
			break;
		}

		offset3d = CONFIG_3D_SLIDERSTATE * 30.0f;

		sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sf2d_draw_rectangle(offset3d + -40, 0, 440, 240, RGBA8(0x00, 0x00, 0xFF, 0xFF));
		sf2d_end_frame();

		sf2d_start_frame(GFX_TOP, GFX_RIGHT);
			sf2d_draw_rectangle(0, 0, 400, 240, RGBA8(0xff, 0xf9, 0x00, 0xFF));
		sf2d_end_frame();

		sf2d_swapbuffers();
	}

	sf2d_fini();
	return 0;
}
