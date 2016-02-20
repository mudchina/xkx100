// Room: /d/wuyi/7qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "七曲");
	set("long", @LONG
七曲城高岩上，高高刻着“放生潭”三个大字。九曲溪之所以能
够绿水长流、生灵欢悦，大抵与这个放生潭的警醒不无关系。数百年
来，这三个大字已不仅仅是一种摩崖石刻了。朱熹《九曲棹歌》曰：
“……七曲移舟上碧滩，隐屏仙掌更回看。却怜昨夜峰头雨，添得飞
泉几道寒。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"6qu",
		"north"     : __DIR__"path7",
		"southwest" : __DIR__"8qu",
		"southeast" : __DIR__"shuiguishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1340);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

