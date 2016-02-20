// jiuqing.c

inherit ROOM;

void create()
{
	set("short", "九卿房");
	set("long", @LONG
这里是六部尚书和都察院御史、大理寺卿、通政使司通政使等九卿
官员以及王公、贝勒大臣等候皇上召见的场所, 对面是蒙古王公值房, 
所以也叫"待漏房".
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"qianqingmen",
	]));
	set("coor/x", -190);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}