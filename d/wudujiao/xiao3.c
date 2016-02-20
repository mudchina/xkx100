// Room: /d/wudujiao/xiao3.c

inherit ROOM;

void create()
{
        set("short", "江边小路");
        set("long", @LONG
这里是桃花江边的一条泥土小路，一旁就是清澈的江水。夹岸
连绵不断的桃花灿若云霞，暗香袭人，引来许多蜜蜂在花树间飞舞。
前面有一个木牌(pai)立在路中央,由于风吹日晒，字迹已经模糊了。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"taohua",
                "northwest" : __DIR__"xiao2",
        ]));
        set("item_desc",([
              "pai": " 前方桃花峪......,.....瘴气.....危险。本村之人....闯入。\n村长  苗三斤 \n",
        ]));

	set("coor/x", -44990);
	set("coor/y", -81040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}