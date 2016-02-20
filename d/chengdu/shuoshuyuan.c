// Room: /d/chengdu/shuoshuyuan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "说书院");
	set("long", @LONG
这个书馆是由全国著名的艺人张宝林坐馆，自然生意兴隆。张宝林
一共收了三个弟子。大弟子王诚已深得师傅真传，大部分时间都是他在
说书。二弟子林文易，吃喝嫖赌无所不为，已被逐出师门。小弟子沈金
音，声音如玉珠落盘委婉动听，被誉为“百灵鸟”。
LONG	);
	set("exits", ([
		"east" : __DIR__"shuchang",
	]));
	set("objects", ([
		__DIR__"npc/wangcheng" : 1,
		__DIR__"npc/shenjinyin" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

