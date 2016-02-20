// Room: /d/wudujiao/caodi.c

inherit ROOM;

void create()
{
        set("short", "草地");
        set("long", @LONG
这里是林中的一片空地，四周被参天的古松环抱着，当中是一片绿
油油的草地。草地中央地上有一个拳头大小的小洞，旁边丈许方圆寸草
不生，露出红褐色的土壤。四周一片寂静，草地上阳光明媚，但你的心
情却一也不轻松，这里该不会有什么危险吧？
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"sl7",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}