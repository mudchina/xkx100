// Room: /d/huanggong/huangqin.c

inherit ROOM;

void create()
{
	set("short", "懋勤殿");
	set("long", @LONG
这是皇上放置图书翰墨以及内廷儒臣值班的懋勤殿。乾隆帝少年时
曾在此读书。此处藏书甚多，多为内府编刊的各类新书。天下刑法人命
关天。每年秋后，在此审断一次，故称“秋审”。后世“秋后算账”也
是源于此。被朱笔划勾者，断无生理，称“勾到”或“勾决”。因在懋
勤殿勾决，故又称“懋勤殿勾到”。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"qianqinggong",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wenyoufang" : 1,
	]));

	set("coor/x", -210);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}