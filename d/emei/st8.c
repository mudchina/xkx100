//Room: st8.c 深潭
//Date: Oct. 21 1997 by That
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short","深潭");
    set("long",@LONG
四周黑蒙蒙，什么都看不清。潭水发着恶臭，偶尔还触及一两根不知是人
是兽的枯骨，让你全身直起鸡皮疙瘩。你漂浮在水中，无助至极。情急之下，
四处张望(wang)。
LONG);
    set("no_fight",1);
    set("no_sleep_room",1);
    set("objects", ([
        __DIR__"npc/frog" : 1,
    ]) );
    set("no_clean_up", 0);
	set("coor/x", -6240);
	set("coor/y", -1170);
	set("coor/z", 20);
	setup();
}
void init()
{
    add_action("do_wang", "wang");
}
int do_wang()
{
    object ob;
    ob = this_player();
    message_vision(HIC"$N极目四望，还是发现有出路的，于是求生试探之心大动。\n"NOR, ob);
    switch (random(4))
    {
       case 0 : set("exits/east", __DIR__"st5");break;
       case 1 : set("exits/east", __DIR__"st6");break;
       case 2 : set("exits/east", __DIR__"st7");break;
       default: set("exits/east", __DIR__"st8");
    }
    switch (random(4))
    {
       case 0 : set("exits/west", __DIR__"st5");break;
       case 1 : set("exits/west", __DIR__"st6");break;
       case 2 : set("exits/west", __DIR__"ssyb");break;
       default: set("exits/west", __DIR__"ssyb");
    }
    switch (random(4))
    {
       case 0 : set("exits/south", __DIR__"st5");break;
       case 1 : set("exits/south", __DIR__"st6");break;
       case 2 : set("exits/south", __DIR__"st7");break;
       default: set("exits/south", __DIR__"st8");
    }
    switch (random(4))
    {
       case 0 : set("exits/north", __DIR__"st5");break;
       case 1 : set("exits/north", __DIR__"st6");break;
       case 2 : set("exits/north", __DIR__"st7");break;
       default: set("exits/north", __DIR__"st8");
    }
    remove_call_out("close_out");
    call_out("close_out", 3);
    return 1;
}

void close_out()
{
    if (query("exits/east"))  delete("exits/east");
    if (query("exits/west"))  delete("exits/west");
    if (query("exits/south")) delete("exits/south");
    if (query("exits/north")) delete("exits/north");
}