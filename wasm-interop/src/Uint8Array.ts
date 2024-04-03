export function construct(buffer: ArrayBuffer): Uint8Array {
    return new Uint8Array(buffer);
}
export function set(from: Uint8Array, to: Uint8Array) {
    from.set(to);
}
export function buffer(buffer: Uint8Array) {
    return buffer.buffer;
}
