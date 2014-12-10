#define ADV7611_MAP_CEC 0
#define ADV7611_MAP_INFOFRAME 1
#define ADV7611_MAP_DPLL 2
#define ADV7611_MAP_KSV 3
#define ADV7611_MAP_EDID 4
#define ADV7611_MAP_HDMI 5
#define ADV7611_MAP_CP 6

typedef enum regs_ADV7611_IO
{	
	ADV7611_IO_VIDEO_STANDARD = 0x00,
	ADV7611_IO_PRIMARY_MODE = 0x01,
	ADV7611_IO_REG_02 = 0x02,
	ADV7611_IO_REG_03 = 0x03,
	ADV7611_IO_REG_04 = 0x04,
	ADV7611_IO_REG_05 = 0x05,
	ADV7611_IO_REG_06 = 0x06,
	ADV7611_IO_REG_0B = 0x0B,
	ADV7611_IO_REG_0C = 0x0C,
	ADV7611_IO_REG_12 = 0x12,
	ADV7611_IO_REG_14 = 0x14,
	ADV7611_IO_REG_15 = 0x15,
	ADV7611_IO_LLC_DLL = 0x19,
	ADV7611_IO_ALSB_CONTROL = 0x1B,
	ADV7611_IO_HPA_REG1 = 0x20,
	ADV7611_IO_HPA_REG2 = 0x21,
	ADV7611_IO_REG_33 = 0x33,
	ADV7611_IO_RD_INFO = 0xEA,
	ADV7611_IO_CEC_SLAVE_ADDR = 0xF4,
	ADV7611_IO_INFOFRAME_SLAVE_ADDR = 0xF5,
	ADV7611_IO_DPLL_SLAVE_ADDR = 0xF6,
	ADV7611_IO_KSV_SLAVE_ADDR = 0xF7,
	ADV7611_IO_EDID_SLAVE_ADDR = 0xF8,
	ADV7611_IO_HDMI_SLAVE_ADDR = 0xF9,
	ADV7611_IO_CP_SLAVE_ADDR = 0xFA,
} __regs_adv7611_io;

typedef struct defs_ADV7611_IO
{
	__regs_adv7611_io reg;
	unsigned char value;
} __defs_adv7611_io;

static int adv7611_read(struct v4l2_subdev *sd, int i2c_addr, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_io_read(struct v4l2_subdev *sd, __regs_adv7611_io reg,
		unsigned char *data, unsigned char len);
static int adv7611_cec_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_infoframe_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_dpll_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_ksv_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_edid_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_hdmi_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_cp_read(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);

static int adv7611_write(struct v4l2_subdev *sd, int i2c_addr, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_io_write(struct v4l2_subdev *sd, __regs_adv7611_io reg,
		unsigned char *data, unsigned char len);
static int adv7611_cec_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_infoframe_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_dpll_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_ksv_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_edid_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_hdmi_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
static int adv7611_cp_write(struct v4l2_subdev *sd, unsigned char reg,
		unsigned char *data, unsigned char len);
