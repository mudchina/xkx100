// yanfeng.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "岩缝");
	set("long", @LONG
忽然，你感觉到被什么东西钩了一下，原来是一棵横着伸出悬崖的
古松止住了下坠之势，细看山崖中裂开了一条大缝，似乎可以由那里攀
缘而下。
LONG );
	set("exits", ([
		"down" : __DIR__"gudi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21060);
	set("coor/z", -30);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="down") 
	tell_object(me,"你攀着岩缝，很艰难地向下爬。哎呀唷。，哎呀。。唷。。\n");
	return ::valid_leave(me,dir);
}