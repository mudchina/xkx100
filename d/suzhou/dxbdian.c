// Room: /d/suzhou/dxbaodian.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long",@long
这里是灵岩寺的大雄宝殿。正中供奉着如来三宝，左右各是文殊、
普贤菩萨。一群青衣小和尚们正在佛像前的地上诵经。缕缕香烟与梵唱
交错在一起，仰视佛祖拈花浅笑的面容，令人顿时生起几分脱俗之感。
身边经常有一队队僧人鱼贯而入，看他们手持戒刀，似乎是巡寺的僧人。
long);
	set("exits",([
		"out"   : __DIR__"lingyansi",
		"north" : __DIR__"cangjingge",
	]));
	set("no_clean_up", 0);
	set("coor/x", 900);
	set("coor/y", -1130);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
