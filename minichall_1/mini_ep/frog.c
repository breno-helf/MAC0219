#include <pthread.h>
#include "frog.h"

void *frog(void *void_frog_args) {
    struct fargs *frog_args = (struct fargs *) void_frog_args;
    int position = frog_args->position;
    // jump direction
    int jd = frog_args->direction ? 1 : -1;
    bool jumped = 0;
    bool in_border = 0;
    while (1) {
        // check boundaries
        if (!frog_args->direction) {
            if (position <= 1) {
                // i am in a border
                in_border = 1;
                if (v[0] != 0) {
                    // there's nothing to do
                    continue;
                }
            }
        }
        else {
            if (position >= frog_args->v_size - 2) {
                // i am in a border
                in_border = 1;
                if (v[frog_args->v_size - 1] != 0) {
                    // there's nothing to do
                    continue;
                }
            }
        }
        // position 0 or n-1 will never get here
        // if it's moving towards the border
        if (v[position + 1 * jd] == 0) {
            // can jump forward
            if (v[position + 1 * jd] == 0) {
                pthread_mutex_lock(frog_args->jump);
                if (v[position + 1 * jd] == 0) {
                    v[position + 1 * jd] = jd
                    position = position + 1 * jd;
                    jumped = 1;
                }
                pthread_mutex_unlock(frog_args->jump);
            }
        }
        if (!in_border) {
            // position 1 and n-2 will never get here
            // if it's moving towards the border
            if (v[position + 2 * jd] == 0) {
                // can leap a friend
                if (v[position + 2 * jd] == 0) {
                    pthread_mutex_lock(frog_args->jump);
                    if (v[position + 2 * jd] == 0) {
                        v[position + 2 * jd] = jd;
                        position = position + 2 * jd;
                        jumped = 1;
                    }
                    pthread_mutex_unlock(frog_args->jump);
                }
            }
        }
        if (!jumped) {
            pthread_mutex_lock(counter_mutex);
            COUNTER++;
            pthread_mutex_unlock(counter_mutex);
        }
    }
}