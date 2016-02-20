// /kaifeng/cangjing2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "藏经楼二层");
	set("long", @LONG
小楼的四个角落中放着石灰包，用来吸收空气中的水份。每隔段时
间，寺庙中的和尚会把收藏在盒中的佛经放到外面去晒以防日久被虫子
蛀了，用来晾晒佛经的石头就称为晒经石，据说有佛力。
LONG);
	set("objects", ([
		BOOK_DIR"fojing2" : random(6),
	]));
	set("exits", ([
		"down" : __DIR__"cangjing1",
	]));

	setup();
	replace_program(ROOM);
}
