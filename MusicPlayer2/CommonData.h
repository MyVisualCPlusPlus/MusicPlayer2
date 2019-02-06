#pragma once
#include "stdafx.h"
#include "ColorConvert.h"
#include "DrawCommon.h"
#include "Common.h"

namespace CONSTVAL
{
	const COLORREF BACKGROUND_COLOR = GRAY(255);		//更改此颜色的值可以修改主窗口背景色
}

struct DeviceInfo	//播放设备的信息
{
	int index;		//设备的索引
	wstring name;	//设备的名称
	wstring driver;	//设备的驱动程序
	DWORD flags;	//设备的状态
};

//选项设置数据
struct LyricSettingData
{
	bool lyric_karaoke_disp{ true };			//可以是否以卡拉OK样式显示
	bool lyric_fuzzy_match{ true };				//歌词模糊匹配
	bool save_lyric_in_offset{};				//是否将歌词保存在offset标签中，还是保存在每个时间标签中
	wstring lyric_path;							//歌词文件夹的路径
	bool show_lyric_in_cortana{};				//是否在Cortana的搜索框中显示歌词
	bool cortana_lyric_double_line{ true };		//是否在Cortana搜索中以双行显示歌词
	int cortana_color{ 0 };						//Cortana搜索框的背景颜色（0：跟随系统，1：黑色，2：白色）
	bool cortana_show_album_cover{ true };		//是否在Cortana搜索框显示专辑封面
	bool cortana_icon_beat{ true };				//Cortana图标随音乐节奏跳动
};

struct ApperanceSettingData
{
	wstring lyric_font_name;					//歌词字体名称
	int lyric_font_size;						//歌词字体大小
	int lyric_line_space{ 2 };					//歌词的行间距
	int window_transparency{ 100 };				//窗口透明度
	ColorTable theme_color;						//主题颜色
	bool theme_color_follow_system{ true };		//主题颜色跟随系统（仅Win8以上支持）
	bool show_album_cover;						//显示专辑封面
	CDrawCommon::StretchMode album_cover_fit{ CDrawCommon::StretchMode::FILL };		//专辑封面契合度（拉伸模式）
	bool album_cover_as_background{ false };	//将专辑封面作为背景
	bool show_spectrum{ true };					//显示频谱分析
	int sprctrum_height{ 100 };					//频谱分析高度比例（%）
	int background_transparency{ 80 };			//背景的透明度
	bool use_out_image{ true };					//使用外部图片作为专辑封面
	bool use_inner_image_first{ true };			//优先使用内嵌专辑封面
	vector<wstring> default_album_name;			//默认的专辑封面文件名
	bool background_gauss_blur{ true };			//背景高斯模糊
	int gauss_blur_radius{ 60 };				//高斯模糊半径*10
	bool lyric_background{ true };				//歌词界面背景
	bool dark_mode{ false };					//深色模式
};

struct GeneralSettingData
{
	bool id3v2_first{ false };					//优先获取ID3V2标签
	bool auto_download_lyric{ false };			//是否自动下载歌词
	bool auto_download_album_cover{ true };		//是否自动下载专辑封面
	bool auto_download_only_tag_full{ true };	//仅在歌曲信息完整时自动下载
	bool check_update_when_start{ true };		//是否在程序启动时检查更新
	wstring sf2_path;							//MIDI音色库路径
	bool midi_use_inner_lyric{ false };			//播放MIDI音乐时显示内嵌歌词
	bool minimize_to_notify_icon{ false };		//是否最小到通知区图标

	Language language;
};

struct PlaySettingData
{
	bool stop_when_error{ true };				//出现错误时停止播放
	bool auto_play_when_start{ false };			//程序启动时自动播放
	bool show_taskbar_progress{ false };		//在任务栏按钮上显示播放进度
	bool show_playstate_icon{ true };			//在任务栏按钮上显示播放状态的角标
	wstring output_device;						//播放设备的名称
	int device_selected{};
};

struct GlobalHotKeySettingData
{
	bool hot_key_enable = true;
	bool global_multimedia_key_enable{ true };	//是否在全局范围内启用多媒体键
};

struct NonCategorizedSettingData
{
	int volum_step{ 3 };			//点击主界面中的音量调节时一次调整的步长
	int mouse_volum_step{ 2 };		//通过鼠标滚轮调节音量时的步长
	int volume_map{ 100 };			//音量映射（例如：如果将此值从100改为60，则当音量设置为最大（100%）时的音量大小为原来的60%）
	bool show_cover_tip{ true };	//是否显示专辑封面上的鼠标提示
	//wstring default_back_image_path{};	//没有专辑封面时的默认背景的路径
	bool no_sf2_warning{ true };	//是否在没有MIDI音色库时弹出提示信息
};

struct IconRes
{
private:
	HICON hIcon;
	HICON hIconDark;
	CSize iconSize;

public:
	const HICON& GetIcon(bool dark = false) const
	{
		return (dark ? hIconDark : hIcon);
	}

	void Load(UINT id, UINT id_dark, int size)
	{
		if (id != 0)
			hIcon = CDrawCommon::LoadIconResource(id, size, size);
		if (id_dark != 0)
			hIconDark = CDrawCommon::LoadIconResource(id_dark, size, size);
		iconSize.cx = iconSize.cy = size;
	}

	const CSize& GetSize() const
	{
		return iconSize;
	}
};
