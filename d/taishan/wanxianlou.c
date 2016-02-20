// Room: /d/taishan/wanxianlou.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "万仙楼");
	set("long", @LONG
万仙楼为跨道门楼式建筑。殿内祀王母，配以列仙，后增祀元君。
殿墙四周镶明代朝山进香碑六十三块。门洞东侧有隐真洞，为旧时道人
修炼处。门洞后额书“谢恩处”，传古帝王登山时，地方官员送驾至此
而谢归。或称旧时香客登岱回归至此无恙，即叩谢元君保佑之恩。
LONG );
	set("exits", ([
		"north" : __DIR__"taohua",
		"south" : __DIR__"sanyibai",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 580);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
