// /kaifeng/xiangguosi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "相国寺门");
	set("long", @LONG
大相国寺占地五百余亩，辖六十四个禅，律院，养僧千余。是京城
最大的寺院和全国佛教活动中心。门前『大相国寺』的匾额乃是当今御
笔亲书。大门敞开，多有行人来往。
LONG);
	set("objects", ([
		__DIR__"npc/zhike" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"qianyuan",
		"south" : __DIR__"jiedao",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
