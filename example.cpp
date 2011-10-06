/*
 * This file is part of Spatosc.
 *
 * Copyright (c) 2010 Society for Arts and Technologies <info@sat.qc.ca>
 *
 * Spatosc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Spatosc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Spatosc.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Manages a example audio scene within Pure Data.
 */

#include "m_pd.h"
#include <cstdio>
#include <sstream>
#include <string>

#define UNUSED(x) ((void) (x))

// The Pd t_class instance, and related object struct:
static t_class *example_class;

typedef struct _example
{
    t_object x_obj;
    //float f_;
	t_outlet *outlet_status;
} t_example;

static void *example_new(t_symbol *s, int argc, t_atom *argv)
{
    UNUSED(s);
    UNUSED(argc);
    UNUSED(argv);
    t_example *x = (t_example *) pd_new(example_class);
    
    // create outlets
    x->outlet_status = outlet_new(&x->x_obj, 0);
    return (x);
}

static void example_free(t_example *x)
{
    UNUSED(x);
    post("[example] freed");
}

static void example_blah(t_example *x, t_symbol *node);

extern "C" void example_setup(void)
{
    example_class = class_new(gensym("example"), (t_newmethod) example_new, (t_method) example_free, sizeof(t_example), CLASS_DEFAULT, A_GIMME, 0);
	class_addmethod(example_class, (t_method) example_blah, gensym("blah"), A_SYMBOL, 0);
    post("[example]: (c) Society for Arts and Technology 2011");
    post("[example]: free software released under the terms of the GNU General Public License.");
    post("[example]: written by Mike Wozniewski, Alexandre Quessy and Tristan Matthews.");
}

static void example_blah(t_example *x, t_symbol *arg)
{
    UNUSED(arg);
	outlet_float(x->outlet_status, 3.14159);
}

