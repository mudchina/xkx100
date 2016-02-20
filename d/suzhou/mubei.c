// Room: /d/suzhou/mubei.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "御书碑");
	set("long",@long
在山之西南麓，有南宋抗金名将韩世忠与梁红玉等四位妻妾的合葬
墓。墓左竖巨碑，碑上篆刻着宋孝宗皇帝御书“中兴佐命定国元勋之碑
”，碑文长达一万三千多字，自古称“天下第一碑”。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"shiyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 895);
	set("coor/y", -1120);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
