// Room: /d/wuyi/yunvfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "玉女峰");
	set("long", @LONG
玉女峰亭亭如少女玉立，突兀挺拔。峰顶花卉参簇，草木苍翠欲滴，
恰似山花插鬓。岩壁秀润光滑，宛如玉肌清凉。她俏立溪畔，凛然不可
侵犯，无路攀登。“插花临水一奇峰，玉骨冰肌处女容”即其写照。峰
下浴香潭，为玉女沐浴处。峰东圆石如镜，是为梳妆台。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"2qu",
		"southeast" : __DIR__"jingtai",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

