/**
 * Stop any X or Y scroll that's currently active.
 */
#define tvcmd_stopscroll() \
	TVCMD_STOPSCROLL

/**
 * Scroll horizontally by relx units, taking time240 to get there.
 */
#define tvcmd_scrollrelx(relx, time240) \
	TVCMD_SCROLLRELX, relx, time240

/**
 * Scroll vertically by rely units, taking time240 to get there.
 */
#define tvcmd_scrollrely(rely, time240) \
	TVCMD_SCROLLRELY, rely, time240

/**
 * Scroll horizontally to an absolute X position, taking time240 to get there.
 */
#define tvcmd_scrollabsx(absx, time240) \
	TVCMD_SCROLLABSX, absx, time240

/**
 * Scroll vertically to an absolute Y position, taking time240 to get there.
 */
#define tvcmd_scrollabsy(absy, time240) \
	TVCMD_SCROLLABSY, absy, time240

/**
 * Scale horizontally to absx scale, taking time240 to get there.
 */
#define tvcmd_scaleabsx(absx, time240) \
	TVCMD_SCALEABSX, absx, time240

/**
 * Scale vertically to absy scale, taking time240 to get there.
 */
#define tvcmd_scaleabsy(absy, time240) \
	TVCMD_SCALEABSY, absy, time240

/**
 * Set the texture to be displayed.
 */
#define tvcmd_settexture(texturenum) \
	TVCMD_SETTEXTURE, texturenum

/**
 * Pause the TV script for the given amount of time.
 */
#define tvcmd_pause(time60) \
	TVCMD_PAUSE, time60

/**
 * Assign a new command list. The value should be a TVCMDLIST constant.
 */
#define tvcmd_setcmdlist(list) \
	TVCMD_SETCMDLIST, list

/**
 * Generate a random number between 0 and 65535, and assign the list if it's
 * lower than the given chance (so higher chance numbers are more likely to
 * change it).
 */
#define tvcmd_randsetcmdlist(list, chance) \
	TVCMD_RANDSETCMDLIST, list, chance

/**
 * Restart the command list from the beginning.
 */
#define tvcmd_restart() \
	TVCMD_RESTART

/**
 * Stop executing the list and yield control back to the engine.
 * A frame will pass before the script is resumed.
 */
#define tvcmd_yield() \
	TVCMD_YIELD

/**
 * Fade to the given RBGA colour, takeing time240 to get there.
 */
#define tvcmd_setcolour(colour, time240) \
	TVCMD_SETCOLOUR, colour, time240

/**
 * Set the absoulte rotation of the image to the given angle.
 * The rotation is instant.
 *
 * The angle is suspected to be in the range 0 to 65536, where 65536 is a full
 * rotation.
 */
#define tvcmd_rotateabs(angle) \
	TVCMD_ROTATEABS, angle

/**
 * Rotate the image by the given angle, relative to its current rotation.
 * The rotation is instant.
 *
 * The angle is suspected to be in the range 0 to 65536, where 65536 is a full
 * rotation.
 */
#define tvcmd_rotaterel(angle) \
	TVCMD_ROTATEREL, angle
