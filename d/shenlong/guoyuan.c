// /d/shenlong/guoyuan.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "果园");
	set("long", @LONG
这是一片果园，种的是一些水果，有苹果、梨头、山楂、桃子、杏
子、梅子等，有的已到的收获时节，枝头已被果实压弯了腰，沉甸甸的，
风一吹枝头一颤一颤的，叫人看了直流口水。西面、北面似乎仍是农田，
南面是山丘，东面是一道山岗。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south" : __DIR__"shanqiu",
	]));
	set("objects", ([
		FRUIT_DIR"apple" : random(2),
		FRUIT_DIR"lizi" : random(2),
		FRUIT_DIR"taozi" : random(2),
		FRUIT_DIR"xingzi" : random(2),
		FRUIT_DIR"yangmei" : random(2),
	]));
	set("snaketype", ({"jinhuan"}));
	setup();
}

#include "snakeroom.h";
