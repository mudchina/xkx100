//TOHTQ7.C

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
山洞中似乎深不可测，洞壁上点着几盏松明，照得洞内一派光亮。
洞内虽然感到十分潮湿，可洞壁干燥坚实，大异平常。
LONG );
	set("exits", ([
		"north"  :__DIR__"htqmen",
		"south"  :__DIR__"tohtq6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 920);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}