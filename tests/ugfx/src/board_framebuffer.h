/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

// Set this to your frame buffer pixel format.
#ifndef GDISP_LLD_PIXELFORMAT
	#define GDISP_LLD_PIXELFORMAT		GDISP_PIXELFORMAT_RGB565
#endif

// Uncomment this if your frame buffer device requires flushing
//#define GDISP_HARDWARE_FLUSH		TRUE
extern uint16_t vgaFramebuffer[480][640];

#ifdef GDISP_DRIVER_VMT

	static void board_init(GDisplay *g, fbInfo *fbi) {
		// TODO: Initialize your frame buffer device here

		// TODO: Set the details of the frame buffer
		int reductBy = 1;
		int vgaWidth = 640;
		int vgaHeight = 480;
		g->g.Width = vgaWidth/reductBy;
		g->g.Height = vgaHeight/reductBy;
		g->g.Backlight = 100;
		g->g.Contrast = 50;
		fbi->linelen = vgaWidth * sizeof(LLDCOLOR_TYPE);				// bytes per row
		fbi->pixels = (uint32_t)vgaFramebuffer
				+ (vgaWidth-g->g.Width)/2 * sizeof(LLDCOLOR_TYPE)
				+ (vgaHeight-g->g.Height)/2*fbi->linelen;												// pointer to the memory frame buffer
	}

	#if GDISP_HARDWARE_FLUSH
		static void board_flush(GDisplay *g) {
			// TODO: Can be an empty function if your hardware doesn't support this
			(void) g;
		}
	#endif

	#if GDISP_NEED_CONTROL
		static void board_backlight(GDisplay *g, uint8_t percent) {
			// TODO: Can be an empty function if your hardware doesn't support this
			(void) g;
			(void) percent;
		}

		static void board_contrast(GDisplay *g, uint8_t percent) {
			// TODO: Can be an empty function if your hardware doesn't support this
			(void) g;
			(void) percent;
		}

		static void board_power(GDisplay *g, powermode_t pwr) {
			// TODO: Can be an empty function if your hardware doesn't support this
			(void) g;
			(void) pwr;
		}
	#endif

#endif /* GDISP_LLD_BOARD_IMPLEMENTATION */
